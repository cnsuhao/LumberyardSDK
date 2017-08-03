#include "StdAfx.h"
#include "PlayFabMatchmakerApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabComboSdk;

// PlayFabMatchmaker Api
PlayFabMatchmakerApi::PlayFabMatchmakerApi() {}

void PlayFabMatchmakerApi::AuthUser(
    MatchmakerModels::AuthUserRequest& request,
    ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/AuthUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAuthUserResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnAuthUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::AuthUserResponse* outResult = new MatchmakerModels::AuthUserResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::AuthUserResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::AuthUserResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerApi::PlayerJoined(
    MatchmakerModels::PlayerJoinedRequest& request,
    ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/PlayerJoined"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerJoinedResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnPlayerJoinedResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::PlayerJoinedResponse* outResult = new MatchmakerModels::PlayerJoinedResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerApi::PlayerLeft(
    MatchmakerModels::PlayerLeftRequest& request,
    ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/PlayerLeft"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerLeftResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnPlayerLeftResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::PlayerLeftResponse* outResult = new MatchmakerModels::PlayerLeftResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::PlayerLeftResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerApi::StartGame(
    MatchmakerModels::StartGameRequest& request,
    ProcessApiCallback<MatchmakerModels::StartGameResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnStartGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::StartGameResponse* outResult = new MatchmakerModels::StartGameResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::StartGameResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::StartGameResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabMatchmakerApi::UserInfo(
    MatchmakerModels::UserInfoRequest& request,
    ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/UserInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUserInfoResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnUserInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::UserInfoResponse* outResult = new MatchmakerModels::UserInfoResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::UserInfoResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::UserInfoResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

