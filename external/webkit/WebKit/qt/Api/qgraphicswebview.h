

#ifndef QGraphicsWebView_h
#define QGraphicsWebView_h

#include "qwebkitglobal.h"
#include "qwebpage.h"
#include <QtCore/qurl.h>
#include <QtGui/qevent.h>
#include <QtGui/qgraphicswidget.h>
#include <QtGui/qicon.h>
#include <QtGui/qpainter.h>
#include <QtNetwork/qnetworkaccessmanager.h>

class QWebPage;
class QWebHistory;
class QWebSettings;

class QGraphicsWebViewPrivate;

class QWEBKIT_EXPORT QGraphicsWebView : public QGraphicsWidget {
    Q_OBJECT

    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QIcon icon READ icon NOTIFY iconChanged)
    Q_PROPERTY(qreal zoomFactor READ zoomFactor WRITE setZoomFactor)

    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)

    Q_PROPERTY(bool modified READ isModified)

public:
    explicit QGraphicsWebView(QGraphicsItem* parent = 0);
    ~QGraphicsWebView();

    QWebPage* page() const;
    void setPage(QWebPage*);

    QUrl url() const;
    void setUrl(const QUrl&);

    QString title() const;
    QIcon icon() const;

    qreal zoomFactor() const;
    void setZoomFactor(qreal);

    bool isModified() const;

    void load(const QUrl &url);
    void load(const QNetworkRequest& request, QNetworkAccessManager::Operation operation = QNetworkAccessManager::GetOperation, const QByteArray& body = QByteArray());

    void setHtml(const QString& html, const QUrl& baseUrl = QUrl());
    // FIXME: Consider rename to setHtml?
    void setContent(const QByteArray& data, const QString& mimeType = QString(), const QUrl& baseUrl = QUrl());

    QWebHistory* history() const;
    QWebSettings* settings() const;

    QAction* pageAction(QWebPage::WebAction action) const;
    void triggerPageAction(QWebPage::WebAction action, bool checked = false);

    bool findText(const QString& subString, QWebPage::FindFlags options = 0);

    virtual void setGeometry(const QRectF& rect);
    virtual void updateGeometry();
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem* options, QWidget* widget = 0);
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value);
    virtual bool event(QEvent*);

    virtual QSizeF sizeHint(Qt::SizeHint which, const QSizeF& constraint) const;

    virtual QVariant inputMethodQuery(Qt::InputMethodQuery query) const;

public Q_SLOTS:
    void stop();
    void back();
    void forward();
    void reload();

Q_SIGNALS:
    void loadStarted();
    void loadFinished(bool);

    void loadProgress(int progress);
    void urlChanged(const QUrl&);
    void titleChanged(const QString&);
    void iconChanged();
    void statusBarMessage(const QString& message);
    void linkClicked(const QUrl&);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent*);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent*);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
#ifndef QT_NO_WHEELEVENT
    virtual void wheelEvent(QGraphicsSceneWheelEvent*);
#endif
    virtual void keyPressEvent(QKeyEvent*);
    virtual void keyReleaseEvent(QKeyEvent*);
#ifndef QT_NO_CONTEXTMENU
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent*);
#endif
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent*);
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent*);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent*);
    virtual void dropEvent(QGraphicsSceneDragDropEvent*);
    virtual void focusInEvent(QFocusEvent*);
    virtual void focusOutEvent(QFocusEvent*);
    virtual void inputMethodEvent(QInputMethodEvent*);
    virtual bool focusNextPrevChild(bool next);

    virtual bool sceneEvent(QEvent*);

private:
    Q_PRIVATE_SLOT(d, void _q_doLoadFinished(bool success))
    // we don't want to change the moc based on USE() macro, so this function is here
    // but will be empty if ACCLERATED_COMPOSITING is disabled
    Q_PRIVATE_SLOT(d, void syncLayers())

    QGraphicsWebViewPrivate* const d;
    friend class QGraphicsWebViewPrivate;
};

#endif // QGraphicsWebView_h