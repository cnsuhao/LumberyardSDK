#pragma once

#include <PlayFabClientSdk/PlayFabError.h>
#include <PlayFabClientSdk/PlayFabDataDataModels.h>
#include <PlayFabClientSdk/PlayFabHttp.h>

namespace PlayFabClientSdk
{
    class PlayFabDataApi
    {
    public:

        // ------------ Generated Api calls
        static void AbortFileUploads(DataModels::AbortFileUploadsRequest& request, ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteFiles(DataModels::DeleteFilesRequest& request, ProcessApiCallback<DataModels::DeleteFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void FinalizeFileUploads(DataModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFiles(DataModels::GetFilesRequest& request, ProcessApiCallback<DataModels::GetFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetObjects(DataModels::GetObjectsRequest& request, ProcessApiCallback<DataModels::GetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InitiateFileUploads(DataModels::InitiateFileUploadsRequest& request, ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetObjects(DataModels::SetObjectsRequest& request, ProcessApiCallback<DataModels::SetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabDataApi();

        // ------------ Generated result handlers
        static void OnAbortFileUploadsResult(PlayFabRequest* request);
        static void OnDeleteFilesResult(PlayFabRequest* request);
        static void OnFinalizeFileUploadsResult(PlayFabRequest* request);
        static void OnGetFilesResult(PlayFabRequest* request);
        static void OnGetObjectsResult(PlayFabRequest* request);
        static void OnInitiateFileUploadsResult(PlayFabRequest* request);
        static void OnSetObjectsResult(PlayFabRequest* request);
    };
};
