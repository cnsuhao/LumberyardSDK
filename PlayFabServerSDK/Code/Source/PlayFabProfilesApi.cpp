#include "StdAfx.h"
#include "PlayFabProfilesApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabServerSdk;

// PlayFabProfiles Api
PlayFabProfilesApi::PlayFabProfilesApi() {}

void PlayFabProfilesApi::GetGlobalPolicy(

    ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/GetGlobalPolicy"), Aws::Http::HttpMethod::HTTP_POST, "", "", "", customData, callback, errorCallback, OnGetGlobalPolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabProfilesApi::OnGetGlobalPolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ProfilesModels::GetGlobalPolicyResponse* outResult = new ProfilesModels::GetGlobalPolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabProfilesApi::GetProfile(
    ProfilesModels::GetEntityProfileRequest& request,
    ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/GetProfile"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetProfileResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabProfilesApi::OnGetProfileResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ProfilesModels::GetEntityProfileResponse* outResult = new ProfilesModels::GetEntityProfileResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> successCallback = reinterpret_cast<ProcessApiCallback<ProfilesModels::GetEntityProfileResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabProfilesApi::GetProfiles(
    ProfilesModels::GetEntityProfilesRequest& request,
    ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/GetProfiles"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetProfilesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabProfilesApi::OnGetProfilesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ProfilesModels::GetEntityProfilesResponse* outResult = new ProfilesModels::GetEntityProfilesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> successCallback = reinterpret_cast<ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabProfilesApi::SetGlobalPolicy(
    ProfilesModels::SetGlobalPolicyRequest& request,
    ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/SetGlobalPolicy"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSetGlobalPolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabProfilesApi::OnSetGlobalPolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ProfilesModels::SetGlobalPolicyResponse* outResult = new ProfilesModels::SetGlobalPolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabProfilesApi::SetProfileLanguage(
    ProfilesModels::SetProfileLanguageRequest& request,
    ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/SetProfileLanguage"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSetProfileLanguageResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabProfilesApi::OnSetProfileLanguageResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ProfilesModels::SetProfileLanguageResponse* outResult = new ProfilesModels::SetProfileLanguageResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> successCallback = reinterpret_cast<ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabProfilesApi::SetProfilePolicy(
    ProfilesModels::SetEntityProfilePolicyRequest& request,
    ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/SetProfilePolicy"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSetProfilePolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabProfilesApi::OnSetProfilePolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ProfilesModels::SetEntityProfilePolicyResponse* outResult = new ProfilesModels::SetEntityProfilePolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

