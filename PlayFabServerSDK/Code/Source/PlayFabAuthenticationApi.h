#pragma once

#include <PlayFabServerSdk/PlayFabError.h>
#include <PlayFabServerSdk/PlayFabAuthenticationDataModels.h>
#include <PlayFabServerSdk/PlayFabHttp.h>

namespace PlayFabServerSdk
{
    class PlayFabAuthenticationApi
    {
    public:

        // ------------ Generated Api calls
        static void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabAuthenticationApi();

        // ------------ Generated result handlers
        static void OnGetEntityTokenResult(PlayFabRequest* request);
    };
};
