
// -*- c++ -*-
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

//                     O S C L _ D N S

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =



#ifndef OSCL_DNS_H_INCLUDED
#define OSCL_DNS_H_INCLUDED

#ifndef OSCLCONFIG_IO_H_INCLUDED
#include "osclconfig_io.h"
#endif

#ifndef OSCL_SOCKET_TYPES_H_INCLUDED
#include "oscl_socket_types.h"
#endif

#ifndef OSCL_DEFALLOC_H_INCLUDED
#include "oscl_defalloc.h"
#endif

#ifndef OSCL_SOCKET_H_INCLUDED
#include "oscl_socket.h"
#endif

enum TPVDNSFxn
{
    EPVDNSGetHostByName
} ;

enum TPVDNSEvent
{
    EPVDNSSuccess
    , EPVDNSPending
    , EPVDNSTimeout
    , EPVDNSFailure
    , EPVDNSCancel
} ;

class OsclDNSObserver
{
    public:
        /**
         * DNS Event callback.
         *
         * @param aId: The ID that was supplied when
         *    the DNS object was created.
         * @param aEvent: Function completion event.  Will be
         *    EPVDNSSuccess, EPVDNSTimeout, or EPVDNSFailure.
         * @param aError: When the event is EPVDNSFailure, this
         *    may contain a platform-specific error code, or zero if
         *    none is available.
         */
        OSCL_IMPORT_REF virtual void HandleDNSEvent(int32 aId, TPVDNSFxn aFxn, TPVDNSEvent aEvent, int32 aError) = 0;

        virtual ~OsclDNSObserver() {}
};

class OsclGetHostByNameMethod;
class OsclDNSI;

class OsclDNS: public HeapBase
{
    public:
        /**
         * DNS object creation.
         *
         * @param alloc: Memory allocator
         * @param aServ: Socket server.
         * @param aObserver: DNS Event observer
         * @param aId: Unique ID for this DNS object.  This ID
         *    will be included in all callbacks associated with
         *    this DNS object.
         */
        OSCL_IMPORT_REF static OsclDNS* NewL(
            Oscl_DefAlloc &alloc,
            OsclSocketServ& aServ,
            OsclDNSObserver & aObserver,
            uint32 aId);

        /**
         * Destructor.
         *
         * Note: the application must de-allocate the DNS object
         *    using the same allocator that was passed in the
         *    NewL object creation call.
         */
        OSCL_IMPORT_REF ~OsclDNS();

        /**
         * GetHostByName.
         *   This is an asynchronous method.
         *
         * @param name: Null-terminated string containing the host
         *    name.
         * @param addr: The output address.  The ipAddr field will
         *    contain the network address of the host in dotted decimal
         *    notation.
         * @param aTimeoutMsec: A timeout for the request in milliseconds,
         *    or (-1) to indicate infinite wait.
         * @returns: EPVDNSPending for success, EPVDNSFailure for failure.
         */
        OSCL_IMPORT_REF TPVDNSEvent GetHostByName(char *name, OsclNetworkAddress& addr,
                int32 aTimeoutMsec = -1);

        /**
         * Cancel GetHostByName
         *
         * This method will cancel any pending GetHostByName operation
         * on the current object, causing the GetHostByName to complete
         * with error EPVDNSCancel.  If there is no pending
         * GetHostByName operation, this method will have no effect.
        */
        OSCL_IMPORT_REF void CancelGetHostByName();

    private:
        OsclDNS(
            Oscl_DefAlloc &alloc,
            OsclDNSObserver& obs,
            uint32 id);
        void ConstructL(OsclSocketServ &aServ);

        OsclGetHostByNameMethod* iGetHostByNameMethod;
        Oscl_DefAlloc& iAlloc;
        OsclDNSObserver& iObserver;
        uint32 iId;
        OsclDNSI *iDNS;
        friend class OsclDNSRequestAO;

};



#endif

