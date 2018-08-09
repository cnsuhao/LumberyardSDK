#include "StdAfx.h"
#include "PlayFabAuthenticationApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabServerSdk;

// PlayFabAuthentication Api
PlayFabAuthenticationApi::PlayFabAuthenticationApi() {}

void PlayFabAuthenticationApi::GetEntityToken(
    AuthenticationModels::GetEntityTokenRequest& request,
    ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Authentication/GetEntityToken"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetEntityTokenResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAuthenticationApi::OnGetEntityTokenResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AuthenticationModels::GetEntityTokenResponse* outResult = new AuthenticationModels::GetEntityTokenResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> successCallback = reinterpret_cast<ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

