#pragma once

#include <PlayFabClientSdk/PlayFabError.h>
#include <PlayFabClientSdk/PlayFabCloudScriptDataModels.h>
#include <PlayFabClientSdk/PlayFabHttp.h>

namespace PlayFabClientSdk
{
    class PlayFabCloudScriptApi
    {
    public:

        // ------------ Generated Api calls
        static void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabCloudScriptApi();

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(PlayFabRequest* request);
    };
};
