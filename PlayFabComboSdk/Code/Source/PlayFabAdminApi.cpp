#include "StdAfx.h"
#include "PlayFabAdminApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabComboSdk;

// PlayFabAdmin Api
PlayFabAdminApi::PlayFabAdminApi() {}

void PlayFabAdminApi::AbortTaskInstance(
    AdminModels::AbortTaskInstanceRequest& request,
    ProcessApiCallback<AdminModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AbortTaskInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAbortTaskInstanceResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAbortTaskInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::EmptyResult* outResult = new AdminModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddNews(
    AdminModels::AddNewsRequest& request,
    ProcessApiCallback<AdminModels::AddNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddNews"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddNewsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddNewsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::AddNewsResult* outResult = new AdminModels::AddNewsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::AddNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::AddNewsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddPlayerTag(
    AdminModels::AddPlayerTagRequest& request,
    ProcessApiCallback<AdminModels::AddPlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddPlayerTag"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddPlayerTagResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddPlayerTagResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::AddPlayerTagResult* outResult = new AdminModels::AddPlayerTagResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::AddPlayerTagResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::AddPlayerTagResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddServerBuild(
    AdminModels::AddServerBuildRequest& request,
    ProcessApiCallback<AdminModels::AddServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddServerBuildResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::AddServerBuildResult* outResult = new AdminModels::AddServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::AddServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::AddServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddUserVirtualCurrency(
    AdminModels::AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyUserVirtualCurrencyResult* outResult = new AdminModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::AddVirtualCurrencyTypes(
    AdminModels::AddVirtualCurrencyTypesRequest& request,
    ProcessApiCallback<AdminModels::BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddVirtualCurrencyTypesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BlankResult* outResult = new AdminModels::BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::BanUsers(
    AdminModels::BanUsersRequest& request,
    ProcessApiCallback<AdminModels::BanUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/BanUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnBanUsersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnBanUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BanUsersResult* outResult = new AdminModels::BanUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BanUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BanUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::CreateActionsOnPlayersInSegmentTask(
    AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request,
    ProcessApiCallback<AdminModels::CreateTaskResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreateActionsOnPlayersInSegmentTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreateActionsOnPlayersInSegmentTaskResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreateActionsOnPlayersInSegmentTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreateTaskResult* outResult = new AdminModels::CreateTaskResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreateTaskResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreateTaskResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::CreateCloudScriptTask(
    AdminModels::CreateCloudScriptTaskRequest& request,
    ProcessApiCallback<AdminModels::CreateTaskResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreateCloudScriptTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreateCloudScriptTaskResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreateCloudScriptTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreateTaskResult* outResult = new AdminModels::CreateTaskResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreateTaskResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreateTaskResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::CreatePlayerSharedSecret(
    AdminModels::CreatePlayerSharedSecretRequest& request,
    ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreatePlayerSharedSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreatePlayerSharedSecretResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreatePlayerSharedSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreatePlayerSharedSecretResult* outResult = new AdminModels::CreatePlayerSharedSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::CreatePlayerStatisticDefinition(
    AdminModels::CreatePlayerStatisticDefinitionRequest& request,
    ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreatePlayerStatisticDefinition"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreatePlayerStatisticDefinitionResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreatePlayerStatisticDefinitionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreatePlayerStatisticDefinitionResult* outResult = new AdminModels::CreatePlayerStatisticDefinitionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeleteContent(
    AdminModels::DeleteContentRequest& request,
    ProcessApiCallback<AdminModels::BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteContent"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteContentResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteContentResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BlankResult* outResult = new AdminModels::BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeletePlayer(
    AdminModels::DeletePlayerRequest& request,
    ProcessApiCallback<AdminModels::DeletePlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeletePlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeletePlayerResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeletePlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeletePlayerResult* outResult = new AdminModels::DeletePlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeletePlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeletePlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeletePlayerSharedSecret(
    AdminModels::DeletePlayerSharedSecretRequest& request,
    ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeletePlayerSharedSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeletePlayerSharedSecretResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeletePlayerSharedSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeletePlayerSharedSecretResult* outResult = new AdminModels::DeletePlayerSharedSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeleteStore(
    AdminModels::DeleteStoreRequest& request,
    ProcessApiCallback<AdminModels::DeleteStoreResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteStore"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteStoreResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteStoreResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeleteStoreResult* outResult = new AdminModels::DeleteStoreResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeleteStoreResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeleteStoreResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeleteTask(
    AdminModels::DeleteTaskRequest& request,
    ProcessApiCallback<AdminModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteTaskResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::EmptyResult* outResult = new AdminModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::DeleteTitle(

    ProcessApiCallback<AdminModels::DeleteTitleResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteTitle"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnDeleteTitleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteTitleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeleteTitleResult* outResult = new AdminModels::DeleteTitleResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeleteTitleResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeleteTitleResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetActionsOnPlayersInSegmentTaskInstance(
    AdminModels::GetTaskInstanceRequest& request,
    ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetActionsOnPlayersInSegmentTaskInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetActionsOnPlayersInSegmentTaskInstanceResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetActionsOnPlayersInSegmentTaskInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult* outResult = new AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetAllSegments(

    ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetAllSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetAllSegmentsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetAllSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetAllSegmentsResult* outResult = new AdminModels::GetAllSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetAllSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetAllSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetCatalogItems(
    AdminModels::GetCatalogItemsRequest& request,
    ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCatalogItemsResult* outResult = new AdminModels::GetCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetCloudScriptRevision(
    AdminModels::GetCloudScriptRevisionRequest& request,
    ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCloudScriptRevision"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCloudScriptRevisionResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptRevisionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCloudScriptRevisionResult* outResult = new AdminModels::GetCloudScriptRevisionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetCloudScriptTaskInstance(
    AdminModels::GetTaskInstanceRequest& request,
    ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCloudScriptTaskInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCloudScriptTaskInstanceResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptTaskInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCloudScriptTaskInstanceResult* outResult = new AdminModels::GetCloudScriptTaskInstanceResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetCloudScriptVersions(

    ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCloudScriptVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetCloudScriptVersionsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCloudScriptVersionsResult* outResult = new AdminModels::GetCloudScriptVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetContentList(
    AdminModels::GetContentListRequest& request,
    ProcessApiCallback<AdminModels::GetContentListResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetContentList"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentListResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetContentListResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetContentListResult* outResult = new AdminModels::GetContentListResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetContentListResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetContentListResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetContentUploadUrl(
    AdminModels::GetContentUploadUrlRequest& request,
    ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetContentUploadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentUploadUrlResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetContentUploadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetContentUploadUrlResult* outResult = new AdminModels::GetContentUploadUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetContentUploadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetContentUploadUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetDataReport(
    AdminModels::GetDataReportRequest& request,
    ProcessApiCallback<AdminModels::GetDataReportResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetDataReport"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetDataReportResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetDataReportResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetDataReportResult* outResult = new AdminModels::GetDataReportResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetDataReportResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetDataReportResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetMatchmakerGameInfo(
    AdminModels::GetMatchmakerGameInfoRequest& request,
    ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetMatchmakerGameInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetMatchmakerGameInfoResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetMatchmakerGameInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetMatchmakerGameInfoResult* outResult = new AdminModels::GetMatchmakerGameInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetMatchmakerGameModes(
    AdminModels::GetMatchmakerGameModesRequest& request,
    ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetMatchmakerGameModes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetMatchmakerGameModesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetMatchmakerGameModesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetMatchmakerGameModesResult* outResult = new AdminModels::GetMatchmakerGameModesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayerSegments(
    AdminModels::GetPlayersSegmentsRequest& request,
    ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerSegmentsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerSegmentsResult* outResult = new AdminModels::GetPlayerSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayerSharedSecrets(

    ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerSharedSecrets"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetPlayerSharedSecretsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerSharedSecretsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerSharedSecretsResult* outResult = new AdminModels::GetPlayerSharedSecretsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayersInSegment(
    AdminModels::GetPlayersInSegmentRequest& request,
    ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayersInSegment"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayersInSegmentResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayersInSegmentResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayersInSegmentResult* outResult = new AdminModels::GetPlayersInSegmentResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayersInSegmentResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayerStatisticDefinitions(

    ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerStatisticDefinitions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetPlayerStatisticDefinitionsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerStatisticDefinitionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerStatisticDefinitionsResult* outResult = new AdminModels::GetPlayerStatisticDefinitionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayerStatisticVersions(
    AdminModels::GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerStatisticVersionsResult* outResult = new AdminModels::GetPlayerStatisticVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPlayerTags(
    AdminModels::GetPlayerTagsRequest& request,
    ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerTags"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTagsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerTagsResult* outResult = new AdminModels::GetPlayerTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPolicy(
    AdminModels::GetPolicyRequest& request,
    ProcessApiCallback<AdminModels::GetPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPolicy"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPolicyResponse* outResult = new AdminModels::GetPolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetPublisherData(
    AdminModels::GetPublisherDataRequest& request,
    ProcessApiCallback<AdminModels::GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPublisherDataResult* outResult = new AdminModels::GetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetRandomResultTables(
    AdminModels::GetRandomResultTablesRequest& request,
    ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetRandomResultTables"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetRandomResultTablesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetRandomResultTablesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetRandomResultTablesResult* outResult = new AdminModels::GetRandomResultTablesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetRandomResultTablesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetRandomResultTablesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetServerBuildInfo(
    AdminModels::GetServerBuildInfoRequest& request,
    ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetServerBuildInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetServerBuildInfoResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetServerBuildInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetServerBuildInfoResult* outResult = new AdminModels::GetServerBuildInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetServerBuildInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetServerBuildInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetServerBuildUploadUrl(
    AdminModels::GetServerBuildUploadURLRequest& request,
    ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetServerBuildUploadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetServerBuildUploadUrlResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetServerBuildUploadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetServerBuildUploadURLResult* outResult = new AdminModels::GetServerBuildUploadURLResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetStoreItems(
    AdminModels::GetStoreItemsRequest& request,
    ProcessApiCallback<AdminModels::GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetStoreItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetStoreItemsResult* outResult = new AdminModels::GetStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetTaskInstances(
    AdminModels::GetTaskInstancesRequest& request,
    ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTaskInstances"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTaskInstancesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTaskInstancesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTaskInstancesResult* outResult = new AdminModels::GetTaskInstancesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTaskInstancesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTaskInstancesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetTasks(
    AdminModels::GetTasksRequest& request,
    ProcessApiCallback<AdminModels::GetTasksResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTasks"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTasksResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTasksResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTasksResult* outResult = new AdminModels::GetTasksResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTasksResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTasksResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetTitleData(
    AdminModels::GetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTitleDataResult* outResult = new AdminModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetTitleInternalData(
    AdminModels::GetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleInternalDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTitleInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTitleDataResult* outResult = new AdminModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserAccountInfo(
    AdminModels::LookupUserAccountInfoRequest& request,
    ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserAccountInfoResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::LookupUserAccountInfoResult* outResult = new AdminModels::LookupUserAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::LookupUserAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserBans(
    AdminModels::GetUserBansRequest& request,
    ProcessApiCallback<AdminModels::GetUserBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserBansResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserBansResult* outResult = new AdminModels::GetUserBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserBansResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserInternalData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInternalDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserInventory(
    AdminModels::GetUserInventoryRequest& request,
    ProcessApiCallback<AdminModels::GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInventoryResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserInventoryResult* outResult = new AdminModels::GetUserInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserPublisherData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserPublisherInternalData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherInternalDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserPublisherReadOnlyData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GetUserReadOnlyData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::GrantItemsToUsers(
    AdminModels::GrantItemsToUsersRequest& request,
    ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GrantItemsToUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToUsersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGrantItemsToUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GrantItemsToUsersResult* outResult = new AdminModels::GrantItemsToUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GrantItemsToUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GrantItemsToUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::IncrementPlayerStatisticVersion(
    AdminModels::IncrementPlayerStatisticVersionRequest& request,
    ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/IncrementPlayerStatisticVersion"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnIncrementPlayerStatisticVersionResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnIncrementPlayerStatisticVersionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::IncrementPlayerStatisticVersionResult* outResult = new AdminModels::IncrementPlayerStatisticVersionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ListServerBuilds(

    ProcessApiCallback<AdminModels::ListBuildsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ListServerBuilds"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnListServerBuildsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnListServerBuildsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ListBuildsResult* outResult = new AdminModels::ListBuildsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ListBuildsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ListBuildsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ListVirtualCurrencyTypes(

    ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ListVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnListVirtualCurrencyTypesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnListVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ListVirtualCurrencyTypesResult* outResult = new AdminModels::ListVirtualCurrencyTypesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ModifyMatchmakerGameModes(
    AdminModels::ModifyMatchmakerGameModesRequest& request,
    ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ModifyMatchmakerGameModes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyMatchmakerGameModesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnModifyMatchmakerGameModesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyMatchmakerGameModesResult* outResult = new AdminModels::ModifyMatchmakerGameModesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ModifyServerBuild(
    AdminModels::ModifyServerBuildRequest& request,
    ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ModifyServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyServerBuildResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnModifyServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyServerBuildResult* outResult = new AdminModels::ModifyServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RefundPurchase(
    AdminModels::RefundPurchaseRequest& request,
    ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RefundPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRefundPurchaseResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRefundPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RefundPurchaseResponse* outResult = new AdminModels::RefundPurchaseResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RefundPurchaseResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RefundPurchaseResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RemovePlayerTag(
    AdminModels::RemovePlayerTagRequest& request,
    ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RemovePlayerTag"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemovePlayerTagResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRemovePlayerTagResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RemovePlayerTagResult* outResult = new AdminModels::RemovePlayerTagResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RemovePlayerTagResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RemovePlayerTagResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RemoveServerBuild(
    AdminModels::RemoveServerBuildRequest& request,
    ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RemoveServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveServerBuildResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRemoveServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RemoveServerBuildResult* outResult = new AdminModels::RemoveServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RemoveServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RemoveServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RemoveVirtualCurrencyTypes(
    AdminModels::RemoveVirtualCurrencyTypesRequest& request,
    ProcessApiCallback<AdminModels::BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RemoveVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveVirtualCurrencyTypesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRemoveVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BlankResult* outResult = new AdminModels::BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ResetCharacterStatistics(
    AdminModels::ResetCharacterStatisticsRequest& request,
    ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ResetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ResetCharacterStatisticsResult* outResult = new AdminModels::ResetCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ResetUserStatistics(
    AdminModels::ResetUserStatisticsRequest& request,
    ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ResetUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetUserStatisticsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetUserStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ResetUserStatisticsResult* outResult = new AdminModels::ResetUserStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ResetUserStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ResetUserStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::ResolvePurchaseDispute(
    AdminModels::ResolvePurchaseDisputeRequest& request,
    ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ResolvePurchaseDispute"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResolvePurchaseDisputeResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnResolvePurchaseDisputeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ResolvePurchaseDisputeResponse* outResult = new AdminModels::ResolvePurchaseDisputeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RevokeAllBansForUser(
    AdminModels::RevokeAllBansForUserRequest& request,
    ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RevokeAllBansForUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeAllBansForUserResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRevokeAllBansForUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RevokeAllBansForUserResult* outResult = new AdminModels::RevokeAllBansForUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RevokeAllBansForUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RevokeBans(
    AdminModels::RevokeBansRequest& request,
    ProcessApiCallback<AdminModels::RevokeBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RevokeBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeBansResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRevokeBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RevokeBansResult* outResult = new AdminModels::RevokeBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RevokeBansResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RevokeBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RevokeInventoryItem(
    AdminModels::RevokeInventoryItemRequest& request,
    ProcessApiCallback<AdminModels::RevokeInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RevokeInventoryItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeInventoryItemResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRevokeInventoryItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RevokeInventoryResult* outResult = new AdminModels::RevokeInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RevokeInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RevokeInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::RunTask(
    AdminModels::RunTaskRequest& request,
    ProcessApiCallback<AdminModels::RunTaskResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RunTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRunTaskResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRunTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RunTaskResult* outResult = new AdminModels::RunTaskResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RunTaskResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RunTaskResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SendAccountRecoveryEmail(
    AdminModels::SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SendAccountRecoveryEmail"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSendAccountRecoveryEmailResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSendAccountRecoveryEmailResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SendAccountRecoveryEmailResult* outResult = new AdminModels::SendAccountRecoveryEmailResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetCatalogItems(
    AdminModels::UpdateCatalogItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateCatalogItemsResult* outResult = new AdminModels::UpdateCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetPlayerSecret(
    AdminModels::SetPlayerSecretRequest& request,
    ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetPlayerSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPlayerSecretResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPlayerSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetPlayerSecretResult* outResult = new AdminModels::SetPlayerSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetPlayerSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetPlayerSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetPublishedRevision(
    AdminModels::SetPublishedRevisionRequest& request,
    ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetPublishedRevision"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublishedRevisionResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPublishedRevisionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetPublishedRevisionResult* outResult = new AdminModels::SetPublishedRevisionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetPublishedRevisionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetPublishedRevisionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetPublisherData(
    AdminModels::SetPublisherDataRequest& request,
    ProcessApiCallback<AdminModels::SetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublisherDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetPublisherDataResult* outResult = new AdminModels::SetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetStoreItems(
    AdminModels::UpdateStoreItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetStoreItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateStoreItemsResult* outResult = new AdminModels::UpdateStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetTitleData(
    AdminModels::SetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetTitleDataResult* outResult = new AdminModels::SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetTitleInternalData(
    AdminModels::SetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleInternalDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetTitleInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetTitleDataResult* outResult = new AdminModels::SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SetupPushNotification(
    AdminModels::SetupPushNotificationRequest& request,
    ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetupPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetupPushNotificationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetupPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetupPushNotificationResult* outResult = new AdminModels::SetupPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetupPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetupPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::SubtractUserVirtualCurrency(
    AdminModels::SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyUserVirtualCurrencyResult* outResult = new AdminModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateBans(
    AdminModels::UpdateBansRequest& request,
    ProcessApiCallback<AdminModels::UpdateBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateBansResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateBansResult* outResult = new AdminModels::UpdateBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateBansResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateCatalogItems(
    AdminModels::UpdateCatalogItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCatalogItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateCatalogItemsResult* outResult = new AdminModels::UpdateCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateCloudScript(
    AdminModels::UpdateCloudScriptRequest& request,
    ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCloudScriptResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateCloudScriptResult* outResult = new AdminModels::UpdateCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdatePlayerSharedSecret(
    AdminModels::UpdatePlayerSharedSecretRequest& request,
    ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdatePlayerSharedSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerSharedSecretResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdatePlayerSharedSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdatePlayerSharedSecretResult* outResult = new AdminModels::UpdatePlayerSharedSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdatePlayerStatisticDefinition(
    AdminModels::UpdatePlayerStatisticDefinitionRequest& request,
    ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdatePlayerStatisticDefinition"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticDefinitionResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdatePlayerStatisticDefinitionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdatePlayerStatisticDefinitionResult* outResult = new AdminModels::UpdatePlayerStatisticDefinitionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdatePolicy(
    AdminModels::UpdatePolicyRequest& request,
    ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdatePolicy"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdatePolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdatePolicyResponse* outResult = new AdminModels::UpdatePolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdatePolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdatePolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateRandomResultTables(
    AdminModels::UpdateRandomResultTablesRequest& request,
    ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateRandomResultTables"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateRandomResultTablesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateRandomResultTablesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateRandomResultTablesResult* outResult = new AdminModels::UpdateRandomResultTablesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateStoreItems(
    AdminModels::UpdateStoreItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateStoreItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateStoreItemsResult* outResult = new AdminModels::UpdateStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateTask(
    AdminModels::UpdateTaskRequest& request,
    ProcessApiCallback<AdminModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateTaskResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::EmptyResult* outResult = new AdminModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserInternalData(
    AdminModels::UpdateUserInternalDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserInternalDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserPublisherData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserPublisherInternalData(
    AdminModels::UpdateUserInternalDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherInternalDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserPublisherReadOnlyData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserReadOnlyData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabAdminApi::UpdateUserTitleDisplayName(
    AdminModels::UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserTitleDisplayName"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserTitleDisplayNameResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserTitleDisplayNameResult* outResult = new AdminModels::UpdateUserTitleDisplayNameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

