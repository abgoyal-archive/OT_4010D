
#ifndef AV_REC_V_PREVIEW_TEST_H_INCLUDED
#define AV_REC_V_PREVIEW_TEST_H_INCLUDED

#include "test_base.h"


class av_rec_v_preview_test : public test_base
{
    public:
        av_rec_v_preview_test(bool aUseProxy) : test_base(aUseProxy),
                iAudioRecStarted(false),
                iAudioStartRecId(0),
                iAudioStopRecId(0),
                iVideoRecStarted(false),
                iVideoStartRecId(0),
                iVideoStopRecId(0),
                iVideoPreviewStarted(false),
                iIsDisconnected(true)
        {};

        ~av_rec_v_preview_test()
        {
        }

        void test();

        void Run();

        void DoCancel();

        void HandleInformationalEventL(const CPVCmnAsyncInfoEvent& aEvent);

        void CommandCompletedL(const CPVCmnCmdResp& aResponse);


    private:
        bool start_async_test();
        void check_audio_video_started();

        bool check_rec_started()
        {
            return (iAudioRecStarted && iVideoRecStarted);
        }
        bool check_rec_stopped()
        {
            return (!iAudioRecStarted && !iVideoRecStarted);
        }

        bool iAudioRecStarted;
        TPVCmnCommandId iAudioStartRecId;
        TPVCmnCommandId iAudioStopRecId;
        bool iVideoRecStarted;
        TPVCmnCommandId iVideoStartRecId;
        TPVCmnCommandId iVideoStopRecId;
        bool iVideoPreviewStarted;
        bool iIsDisconnected;
};


#endif


