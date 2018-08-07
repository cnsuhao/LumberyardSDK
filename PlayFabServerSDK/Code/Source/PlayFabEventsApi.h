#pragma once

#include <PlayFabServerSdk/PlayFabError.h>
#include <PlayFabServerSdk/PlayFabEventsDataModels.h>
#include <PlayFabServerSdk/PlayFabHttp.h>

namespace PlayFabServerSdk
{
    class PlayFabEventsApi
    {
    public:

        // ------------ Generated Api calls
        static void WriteEvents(EventsModels::WriteEventsRequest& request, ProcessApiCallback<EventsModels::WriteEventsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabEventsApi();

        // ------------ Generated result handlers
        static void OnWriteEventsResult(PlayFabRequest* request);
    };
};
