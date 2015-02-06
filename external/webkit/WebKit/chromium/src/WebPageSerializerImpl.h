

#ifndef WebPageSerializerImpl_h
#define WebPageSerializerImpl_h

#include "PlatformString.h"
#include "StringBuilder.h"
#include "StringHash.h"
#include <wtf/HashMap.h>
#include <wtf/Vector.h>

#include "WebEntities.h"
#include "WebPageSerializer.h"
#include "WebPageSerializerClient.h"
#include "WebString.h"
#include "WebURL.h"

namespace WebCore {
class Document;
class Element;
class Node;
class String;
class TextEncoding;
}

namespace WebKit {
class WebFrameImpl;

// Get html data by serializing all frames of current page with lists
// which contain all resource links that have local copy.
// contain all saved auxiliary files included all sub frames and resources.
// This function will find out all frames and serialize them to HTML data.
// We have a data buffer to temporary saving generated html data. We will
// sequentially call WebViewDelegate::SendSerializedHtmlData once the data
// buffer is full. See comments of WebViewDelegate::SendSerializedHtmlData
// for getting more information.
class WebPageSerializerImpl {
public:
    // Do serialization action. Return false means no available frame has been
    // serialized, otherwise return true.
    bool serialize();

    // The parameter specifies which frame need to be serialized.
    // The parameter recursive_serialization specifies whether we need to
    // serialize all sub frames of the specified frame or not.
    // The parameter delegate specifies the pointer of interface
    // DomSerializerDelegate provide sink interface which can receive the
    // individual chunks of data to be saved.
    // The parameter links contain original URLs of all saved links.
    // The parameter local_paths contain corresponding local file paths of all
    // saved links, which matched with vector:links one by one.
    // The parameter local_directory_name is relative path of directory which
    // contain all saved auxiliary files included all sub frames and resources.
    WebPageSerializerImpl(WebFrame* frame,
                          bool recursive,
                          WebPageSerializerClient* client,
                          const WebVector<WebURL>& links,
                          const WebVector<WebString>& localPaths,
                          const WebString& localDirectoryName);

private:
    // Specified frame which need to be serialized;
    WebFrameImpl* m_specifiedWebFrameImpl;
    // Pointer of WebPageSerializerClient
    WebPageSerializerClient* m_client;
    // This hash map is used to map resource URL of original link to its local
    // file path.
    typedef HashMap<WebCore::String, WebCore::String> LinkLocalPathMap;
    // local_links_ include all pair of local resource path and corresponding
    // original link.
    LinkLocalPathMap m_localLinks;
    // Data buffer for saving result of serialized DOM data.
    WebCore::StringBuilder m_dataBuffer;
    // Passing true to recursive_serialization_ indicates we will serialize not
    // only the specified frame but also all sub-frames in the specific frame.
    // Otherwise we only serialize the specified frame excluded all sub-frames.
    bool m_recursiveSerialization;
    // Flag indicates whether we have collected all frames which need to be
    // serialized or not;
    bool m_framesCollected;
    // Local directory name of all local resource files.
    WebCore::String m_localDirectoryName;
    // Vector for saving all frames which need to be serialized.
    Vector<WebFrameImpl*> m_frames;

    // Web entities conversion maps.
    WebEntities m_htmlEntities;
    WebEntities m_xmlEntities;

    struct SerializeDomParam {
        // Frame URL of current processing document presented by GURL
        const WebCore::KURL& currentFrameURL;
        // Current using text encoding object.
        const WebCore::TextEncoding& textEncoding;

        // Document object of current frame.
        WebCore::Document* doc;
        // Local directory name of all local resource files.
        const WebCore::String& directoryName;

        // Flag indicates current doc is html document or not. It's a cache value
        // of Document.isHTMLDocument().
        bool isHTMLDocument;
        // Flag which indicate whether we have met document type declaration.
        bool hasDoctype;
        // Flag which indicate whether will process meta issue.
        bool hasCheckedMeta;
        // This meta element need to be skipped when serializing DOM.
        const WebCore::Element* skipMetaElement;
        // Flag indicates we are in script or style tag.
        bool isInScriptOrStyleTag;
        // Flag indicates whether we have written xml document declaration.
        // It is only used in xml document
        bool hasDocDeclaration;
        // Flag indicates whether we have added additional contents before end tag.
        // This flag will be re-assigned in each call of function
        // PostActionAfterSerializeOpenTag and it could be changed in function
        // PreActionBeforeSerializeEndTag if the function adds new contents into
        // serialization stream.
        bool hasAddedContentsBeforeEnd;

        // Constructor.
        SerializeDomParam(const WebCore::KURL& currentFrameURL,
                          const WebCore::TextEncoding& textEncoding,
                          WebCore::Document* doc,
                          const WebCore::String& directoryName);
    };

    // Collect all target frames which need to be serialized.
    void collectTargetFrames();
    // Before we begin serializing open tag of a element, we give the target
    // element a chance to do some work prior to add some additional data.
    WebCore::String preActionBeforeSerializeOpenTag(const WebCore::Element* element,
                                                    SerializeDomParam* param,
                                                    bool* needSkip);
    // After we finish serializing open tag of a element, we give the target
    // element a chance to do some post work to add some additional data.
    WebCore::String postActionAfterSerializeOpenTag(const WebCore::Element* element,
                                                    SerializeDomParam* param);
    // Before we begin serializing end tag of a element, we give the target
    // element a chance to do some work prior to add some additional data.
    WebCore::String preActionBeforeSerializeEndTag(const WebCore::Element* element,
                                                   SerializeDomParam* param,
                                                   bool* needSkip);
    // After we finish serializing end tag of a element, we give the target
    // element a chance to do some post work to add some additional data.
    WebCore::String postActionAfterSerializeEndTag(const WebCore::Element* element,
                                                   SerializeDomParam* param);
    // Save generated html content to data buffer.
    void saveHTMLContentToBuffer(const WebCore::String& content,
                                 SerializeDomParam* param);
    // Flushes the content buffer by encoding and sending the content to the
    // WebPageSerializerClient. Content is not flushed if the buffer is not full
    // unless force is 1.
    void encodeAndFlushBuffer(WebPageSerializerClient::PageSerializationStatus status,
                              SerializeDomParam* param,
                              bool force);
    // Serialize open tag of an specified element.
    void openTagToString(const WebCore::Element* element,
                         SerializeDomParam* param);
    // Serialize end tag of an specified element.
    void endTagToString(const WebCore::Element* element,
                        SerializeDomParam* param);
    // Build content for a specified node
    void buildContentForNode(const WebCore::Node* node,
                             SerializeDomParam* param);
};

} // namespace WebKit

#endif
