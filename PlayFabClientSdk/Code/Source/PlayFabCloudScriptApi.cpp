#include "StdAfx.h"
#include "PlayFabCloudScriptApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabClientSdk;

// PlayFabCloudScript Api
PlayFabCloudScriptApi::PlayFabCloudScriptApi() {}

void PlayFabCloudScriptApi::ExecuteEntityCloudScript(
    CloudScriptModels::ExecuteEntityCloudScriptRequest& request,
    ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/CloudScript/ExecuteEntityCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnExecuteEntityCloudScriptResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabCloudScriptApi::OnExecuteEntityCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        CloudScriptModels::ExecuteCloudScriptResult* outResult = new CloudScriptModels::ExecuteCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

