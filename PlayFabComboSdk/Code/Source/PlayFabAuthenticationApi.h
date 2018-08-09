#pragma once

#include <PlayFabComboSdk/PlayFabError.h>
#include <PlayFabComboSdk/PlayFabAuthenticationDataModels.h>
#include <PlayFabComboSdk/PlayFabHttp.h>

namespace PlayFabComboSdk
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
