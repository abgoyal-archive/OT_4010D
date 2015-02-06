
#ifndef AMR_ENC_H_INCLUDED
#define AMR_ENC_H_INCLUDED

#ifndef OSCL_MEM_H_INCLUDED
#include "oscl_mem.h"
#endif

#ifndef OMX_Component_h
#include "OMX_Component.h"
#endif

#ifndef GSMAMR_ENCODER_H_INCLUDED
#include "gsmamr_encoder_wrapper.h"
#endif

#ifndef PVMF_FORMAT_TYPE_H_INCLUDED
#include "pvmf_format_type.h"
#endif



// frame length is 20 milliseconds i.e. 20000 omx ticks/microseconds
#define AMR_FRAME_LENGTH_IN_TIMESTAMP 20000
#define MAX_AMR_FRAME_SIZE 32
#define MAX_NUM_OUTPUT_FRAMES_PER_BUFFER 10


class OmxAmrEncoder
{
    public:
        OmxAmrEncoder();

        OMX_BOOL AmrEncInit(OMX_AUDIO_PARAM_PCMMODETYPE aPcmMode,
                            OMX_AUDIO_PARAM_AMRTYPE aAmrParam,
                            OMX_U32* aInputFrameLength,
                            OMX_U32* aMaxNumberOutputFrames);

        void AmrEncDeinit();

        OMX_BOOL AmrEncodeFrame(OMX_U8* aOutputBuffer,
                                OMX_U32* aOutputLength,
                                OMX_U8* aInBuffer,
                                OMX_U32 aInBufSize,
                                OMX_TICKS aInTimeStamp,
                                OMX_TICKS* aOutTimeStamp);





    private:

        //Codec and encoder settings
        CPvGsmAmrEncoder*  ipGsmEncoder;
        TEncodeProperties* ipEncProps;

        //Encoding Settings parameters

        int32*           ipSizeArrayForOutputFrames;
//        uint32           iNextStartTime;
        OMX_TICKS        iNextStartTime;  // ALPS00121671

        uint32           iMaxNumOutputFramesPerBuffer;
        uint32           iOneInputFrameLength;
        uint32           iMaxInputSize;
        PVMFFormatType   iOutputFormat;

        OMX_S32 iAmrInitFlag;

};



#endif  //#ifndef AMR_ENC_H_INCLUDED

