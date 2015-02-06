
#include "av_pause_rec_disconnect_test.h"



void av_pause_rec_disconnect_test::test()
{
    fprintf(fileoutput, "Start a/v pause rec disconnect test, proxy %d.\n", iUseProxy);
    int error = 0;

    scheduler = OsclExecScheduler::Current();

    this->AddToScheduler();

    if (start_async_test())
    {
        OSCL_TRY(error, scheduler->StartScheduler());
        if (error != 0)
        {
            OSCL_LEAVE(error);
        }
    }

    destroy_sink_source();

    this->RemoveFromScheduler();
}


void av_pause_rec_disconnect_test::Run()
{
    if (terminal)
    {
        if (iUseProxy)
        {
            CPV2WayProxyFactory::DeleteTerminal(terminal);
        }
        else
        {
            CPV2WayEngineFactory::DeleteTerminal(terminal);
        }
        terminal = NULL;
    }

    scheduler->StopScheduler();
}

void av_pause_rec_disconnect_test::DoCancel()
{
}

void av_pause_rec_disconnect_test::HandleInformationalEventL(const CPVCmnAsyncInfoEvent& aEvent)
{
    int error = 0;

    switch (aEvent.GetEventType())
    {
        case PVT_INDICATION_INCOMING_TRACK:
            TPVChannelId id;

            if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_VIDEO)
            {
                OSCL_TRY(error, iVideoAddSinkId = terminal->AddDataSinkL(*iVideoSink, id));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }
            }

            if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_AUDIO)
            {
                OSCL_TRY(error, iAudioAddSinkId = terminal->AddDataSinkL(*iAudioSink, id));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }
            }
            break;

        case PVT_INDICATION_DISCONNECT:
            iAudioSourceAdded = false;
            iVideoSourceAdded = false;
            iAudioSinkAdded = false;
            iVideoSinkAdded = false;
            break;

        case PVT_INDICATION_CLOSE_TRACK:
            if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_VIDEO)
            {
                if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[1] == INCOMING)
                {
                    iVideoSinkAdded = false;
                }
                else
                {
                    iVideoSourceAdded = false;
                }
            }
            else if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_AUDIO)
            {
                if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[1] == INCOMING)
                {
                    iAudioSinkAdded = false;
                }
                else
                {
                    iAudioSourceAdded = false;
                }
            }
            break;

        case PVT_INDICATION_INTERNAL_ERROR:
            break;

        default:
            break;
    }
}

void av_pause_rec_disconnect_test::CommandCompletedL(const CPVCmnCmdResp& aResponse)
{
    int error = 0;
    switch (aResponse.GetCmdType())
    {
        case PVT_COMMAND_INIT:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_wHeapString<OsclMemAllocator> filename(RECORDED_CALL_FILENAME);
                OSCL_TRY(error, terminal->InitRecordFileL(filename));
                if (error)
                {
                    test_is_true(false);
                    reset();
                }
            }
            else
            {
                test_is_true(false);
                RunIfNotReady();
            }
            break;

        case PVT_COMMAND_RESET:
            RunIfNotReady();
            break;

        case PVT_COMMAND_ADD_DATA_SOURCE:
            if (aResponse.GetCmdId() == iAudioAddSourceId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iAudioSourceAdded = true;

                    if (check_audio_started() && check_video_started())
                    {
                        OSCL_TRY(error, iAudioStartRecId = terminal->StartRecordL(*iAudioSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }

                        OSCL_TRY(error, iVideoStartRecId = terminal->StartRecordL(*iVideoSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iAudioAddSourceId = 0;
            }
            else if (aResponse.GetCmdId() == iVideoAddSourceId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iVideoSourceAdded = true;

                    if (check_audio_started() && check_video_started())
                    {
                        OSCL_TRY(error, iAudioStartRecId = terminal->StartRecordL(*iAudioSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }

                        OSCL_TRY(error, iVideoStartRecId = terminal->StartRecordL(*iVideoSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iVideoAddSourceId = 0;
            }
            break;

        case PVT_COMMAND_REMOVE_DATA_SOURCE:
            if (aResponse.GetCmdId() == iAudioRemoveSourceId)
            {
                iAudioRemoveSourceId = 0;
                iAudioSourceAdded = false;
            }
            else if (aResponse.GetCmdId() == iVideoRemoveSourceId)
            {
                iVideoRemoveSourceId = 0;
                iVideoSourceAdded = false;
            }
            break;

        case PVT_COMMAND_ADD_DATA_SINK:
            if (aResponse.GetCmdId() == iAudioAddSinkId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iAudioSinkAdded = true;

                    if (check_audio_started() && check_video_started())
                    {
                        OSCL_TRY(error, iAudioStartRecId = terminal->StartRecordL(*iAudioSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }

                        OSCL_TRY(error, iVideoStartRecId = terminal->StartRecordL(*iVideoSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iAudioAddSinkId = 0;
            }
            else if (aResponse.GetCmdId() == iVideoAddSinkId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iVideoSinkAdded = true;

                    if (check_audio_started() && check_video_started())
                    {
                        OSCL_TRY(error, iAudioStartRecId = terminal->StartRecordL(*iAudioSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }

                        OSCL_TRY(error, iVideoStartRecId = terminal->StartRecordL(*iVideoSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iVideoAddSinkId = 0;
            }
            break;

        case PVT_COMMAND_REMOVE_DATA_SINK:
            if (aResponse.GetCmdId() == iAudioRemoveSinkId)
            {
                iAudioRemoveSinkId = 0;
                iAudioSinkAdded = false;
            }
            else if (aResponse.GetCmdId() == iVideoRemoveSinkId)
            {
                iVideoRemoveSinkId  = 0;
                iVideoSinkAdded = false;
            }
            break;

        case PVT_COMMAND_CONNECT:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_TRY(error, iAudioAddSourceId = terminal->AddDataSourceL(*iAudioSource));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }

                OSCL_TRY(error, iVideoAddSourceId = terminal->AddDataSourceL(*iVideoSource));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }
            }
            else
            {
                test_is_true(false);
                reset();
            }
            break;

        case PVT_COMMAND_DISCONNECT:
            iAudioSourceAdded = false;
            iVideoSourceAdded = false;
            iAudioSinkAdded = false;
            iVideoSinkAdded = false;

            test_is_true(true);

            OSCL_TRY(error, terminal->ResetRecordFileL());
            if (error)
            {
                reset();
            }
            break;

        case PVT_COMMAND_INIT_RECORD_FILE:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_TRY(error, terminal->ConnectL(iConnectOptions));
                if (error)
                {
                    test_is_true(false);
                    reset();
                }
            }
            else
            {
                test_is_true(false);
                reset();
            }
            break;

        case PVT_COMMAND_RESET_RECORD_FILE:
            reset();
            break;

        case PVT_COMMAND_START_RECORD:
            if (aResponse.GetCmdId() == iAudioStartRecId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    OSCL_TRY(error, iAudioPauseRecId = terminal->PauseRecordL(*iAudioSink));
                    if (error)
                    {
                        test_is_true(false);
                        disconnect();
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iAudioStartRecId = 0;
            }
            else if (aResponse.GetCmdId() == iVideoStartRecId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    OSCL_TRY(error, iVideoPauseRecId = terminal->PauseRecordL(*iVideoSink));
                    if (error)
                    {
                        test_is_true(false);
                        disconnect();
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iVideoStartRecId = 0;
            }
            break;

        case PVT_COMMAND_PAUSE_RECORD:
            if (aResponse.GetCmdId() == iAudioPauseRecId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iAudioRecPaused = true;

                    if (check_rec_paused())
                    {
                        disconnect();
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iAudioPauseRecId = 0;
            }
            else if (aResponse.GetCmdId() == iVideoPauseRecId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iVideoRecPaused = true;

                    if (check_rec_paused())
                    {
                        disconnect();
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iVideoPauseRecId = 0;
            }
            break;
    }
}

bool av_pause_rec_disconnect_test::start_async_test()
{
    int error = 0;

    if (iUseProxy)
    {
        OSCL_TRY(error, terminal = CPV2WayProxyFactory::CreateTerminalL(PV_324M,
                                   (MPVCmnCmdStatusObserver *) this,
                                   (MPVCmnInfoEventObserver *) this,
                                   (MPVCmnErrorEventObserver *) this));
    }
    else
    {
        OSCL_TRY(error, terminal = CPV2WayEngineFactory::CreateTerminalL(PV_324M,
                                   (MPVCmnCmdStatusObserver *) this,
                                   (MPVCmnInfoEventObserver *) this,
                                   (MPVCmnErrorEventObserver *) this));
    }

    if (error)
    {
        test_is_true(false);
        return false;
    }

    create_sink_source();

    OSCL_TRY(error, terminal->InitL(iSdkInitInfo, iCommServer));
    if (error)
    {
        test_is_true(false);
        if (iUseProxy)
        {
            CPV2WayProxyFactory::DeleteTerminal(terminal);
        }
        else
        {
            CPV2WayEngineFactory::DeleteTerminal(terminal);
        }
        terminal = NULL;
        return false;
    }

    return true;
}





