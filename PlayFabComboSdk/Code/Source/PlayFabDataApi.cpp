#include "StdAfx.h"
#include "PlayFabDataApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabComboSdk;

// PlayFabData Api
PlayFabDataApi::PlayFabDataApi() {}

void PlayFabDataApi::AbortFileUploads(
    DataModels::AbortFileUploadsRequest& request,
    ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/AbortFileUploads"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAbortFileUploadsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabDataApi::OnAbortFileUploadsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DataModels::AbortFileUploadsResponse* outResult = new DataModels::AbortFileUploadsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DataModels::AbortFileUploadsResponse> successCallback = reinterpret_cast<ProcessApiCallback<DataModels::AbortFileUploadsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabDataApi::DeleteFiles(
    DataModels::DeleteFilesRequest& request,
    ProcessApiCallback<DataModels::DeleteFilesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/DeleteFiles"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnDeleteFilesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabDataApi::OnDeleteFilesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DataModels::DeleteFilesResponse* outResult = new DataModels::DeleteFilesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DataModels::DeleteFilesResponse> successCallback = reinterpret_cast<ProcessApiCallback<DataModels::DeleteFilesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabDataApi::FinalizeFileUploads(
    DataModels::FinalizeFileUploadsRequest& request,
    ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/FinalizeFileUploads"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnFinalizeFileUploadsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabDataApi::OnFinalizeFileUploadsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DataModels::FinalizeFileUploadsResponse* outResult = new DataModels::FinalizeFileUploadsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> successCallback = reinterpret_cast<ProcessApiCallback<DataModels::FinalizeFileUploadsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabDataApi::GetFiles(
    DataModels::GetFilesRequest& request,
    ProcessApiCallback<DataModels::GetFilesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/GetFiles"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetFilesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabDataApi::OnGetFilesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DataModels::GetFilesResponse* outResult = new DataModels::GetFilesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DataModels::GetFilesResponse> successCallback = reinterpret_cast<ProcessApiCallback<DataModels::GetFilesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabDataApi::GetObjects(
    DataModels::GetObjectsRequest& request,
    ProcessApiCallback<DataModels::GetObjectsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Object/GetObjects"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetObjectsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabDataApi::OnGetObjectsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DataModels::GetObjectsResponse* outResult = new DataModels::GetObjectsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DataModels::GetObjectsResponse> successCallback = reinterpret_cast<ProcessApiCallback<DataModels::GetObjectsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabDataApi::InitiateFileUploads(
    DataModels::InitiateFileUploadsRequest& request,
    ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/InitiateFileUploads"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnInitiateFileUploadsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabDataApi::OnInitiateFileUploadsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DataModels::InitiateFileUploadsResponse* outResult = new DataModels::InitiateFileUploadsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DataModels::InitiateFileUploadsResponse> successCallback = reinterpret_cast<ProcessApiCallback<DataModels::InitiateFileUploadsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabDataApi::SetObjects(
    DataModels::SetObjectsRequest& request,
    ProcessApiCallback<DataModels::SetObjectsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Object/SetObjects"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSetObjectsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabDataApi::OnSetObjectsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        DataModels::SetObjectsResponse* outResult = new DataModels::SetObjectsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<DataModels::SetObjectsResponse> successCallback = reinterpret_cast<ProcessApiCallback<DataModels::SetObjectsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

