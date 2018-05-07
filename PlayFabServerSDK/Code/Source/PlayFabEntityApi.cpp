#include "StdAfx.h"
#include "PlayFabEntityApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabServerSdk;

// PlayFabEntity Api
PlayFabEntityApi::PlayFabEntityApi() {}

void PlayFabEntityApi::AbortFileUploads(
    EntityModels::AbortFileUploadsRequest& request,
    ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/AbortFileUploads"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAbortFileUploadsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnAbortFileUploadsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::AbortFileUploadsResponse* outResult = new EntityModels::AbortFileUploadsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::AbortFileUploadsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::AbortFileUploadsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::AcceptGroupApplication(
    EntityModels::AcceptGroupApplicationRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/AcceptGroupApplication"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAcceptGroupApplicationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnAcceptGroupApplicationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::AcceptGroupInvitation(
    EntityModels::AcceptGroupInvitationRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/AcceptGroupInvitation"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAcceptGroupInvitationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnAcceptGroupInvitationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::AddMembers(
    EntityModels::AddMembersRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/AddMembers"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAddMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnAddMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ApplyToGroup(
    EntityModels::ApplyToGroupRequest& request,
    ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ApplyToGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnApplyToGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnApplyToGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::ApplyToGroupResponse* outResult = new EntityModels::ApplyToGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::ApplyToGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::ApplyToGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::BlockEntity(
    EntityModels::BlockEntityRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/BlockEntity"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnBlockEntityResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnBlockEntityResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ChangeMemberRole(
    EntityModels::ChangeMemberRoleRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ChangeMemberRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnChangeMemberRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnChangeMemberRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::CreateGroup(
    EntityModels::CreateGroupRequest& request,
    ProcessApiCallback<EntityModels::CreateGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/CreateGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnCreateGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnCreateGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::CreateGroupResponse* outResult = new EntityModels::CreateGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::CreateGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::CreateGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::CreateRole(
    EntityModels::CreateGroupRoleRequest& request,
    ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/CreateRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnCreateRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnCreateRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::CreateGroupRoleResponse* outResult = new EntityModels::CreateGroupRoleResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::CreateGroupRoleResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::CreateGroupRoleResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::DeleteFiles(
    EntityModels::DeleteFilesRequest& request,
    ProcessApiCallback<EntityModels::DeleteFilesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/DeleteFiles"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnDeleteFilesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnDeleteFilesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::DeleteFilesResponse* outResult = new EntityModels::DeleteFilesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::DeleteFilesResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::DeleteFilesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::DeleteGroup(
    EntityModels::DeleteGroupRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/DeleteGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnDeleteGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnDeleteGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::DeleteRole(
    EntityModels::DeleteRoleRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/DeleteRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnDeleteRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnDeleteRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::FinalizeFileUploads(
    EntityModels::FinalizeFileUploadsRequest& request,
    ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/FinalizeFileUploads"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnFinalizeFileUploadsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnFinalizeFileUploadsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::FinalizeFileUploadsResponse* outResult = new EntityModels::FinalizeFileUploadsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::GetEntityToken(
    EntityModels::GetEntityTokenRequest& request,
    ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Authentication/GetEntityToken"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetEntityTokenResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnGetEntityTokenResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::GetEntityTokenResponse* outResult = new EntityModels::GetEntityTokenResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::GetEntityTokenResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::GetEntityTokenResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::GetFiles(
    EntityModels::GetFilesRequest& request,
    ProcessApiCallback<EntityModels::GetFilesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/GetFiles"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetFilesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnGetFilesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::GetFilesResponse* outResult = new EntityModels::GetFilesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::GetFilesResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::GetFilesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::GetGlobalPolicy(

    ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/GetGlobalPolicy"), Aws::Http::HttpMethod::HTTP_POST, "", "", "", customData, callback, errorCallback, OnGetGlobalPolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnGetGlobalPolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::GetGlobalPolicyResponse* outResult = new EntityModels::GetGlobalPolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::GetGlobalPolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::GetGroup(
    EntityModels::GetGroupRequest& request,
    ProcessApiCallback<EntityModels::GetGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/GetGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnGetGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::GetGroupResponse* outResult = new EntityModels::GetGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::GetGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::GetGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::GetObjects(
    EntityModels::GetObjectsRequest& request,
    ProcessApiCallback<EntityModels::GetObjectsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Object/GetObjects"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetObjectsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnGetObjectsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::GetObjectsResponse* outResult = new EntityModels::GetObjectsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::GetObjectsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::GetObjectsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::GetProfile(
    EntityModels::GetEntityProfileRequest& request,
    ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/GetProfile"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetProfileResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnGetProfileResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::GetEntityProfileResponse* outResult = new EntityModels::GetEntityProfileResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::GetEntityProfileResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::GetEntityProfileResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::GetProfiles(
    EntityModels::GetEntityProfilesRequest& request,
    ProcessApiCallback<EntityModels::GetEntityProfilesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/GetProfiles"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetProfilesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnGetProfilesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::GetEntityProfilesResponse* outResult = new EntityModels::GetEntityProfilesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::GetEntityProfilesResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::GetEntityProfilesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::InitiateFileUploads(
    EntityModels::InitiateFileUploadsRequest& request,
    ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/File/InitiateFileUploads"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnInitiateFileUploadsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnInitiateFileUploadsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::InitiateFileUploadsResponse* outResult = new EntityModels::InitiateFileUploadsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::InitiateFileUploadsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::InviteToGroup(
    EntityModels::InviteToGroupRequest& request,
    ProcessApiCallback<EntityModels::InviteToGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/InviteToGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnInviteToGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnInviteToGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::InviteToGroupResponse* outResult = new EntityModels::InviteToGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::InviteToGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::InviteToGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::IsMember(
    EntityModels::IsMemberRequest& request,
    ProcessApiCallback<EntityModels::IsMemberResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/IsMember"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnIsMemberResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnIsMemberResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::IsMemberResponse* outResult = new EntityModels::IsMemberResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::IsMemberResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::IsMemberResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ListGroupApplications(
    EntityModels::ListGroupApplicationsRequest& request,
    ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupApplications"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupApplicationsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnListGroupApplicationsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::ListGroupApplicationsResponse* outResult = new EntityModels::ListGroupApplicationsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::ListGroupApplicationsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ListGroupBlocks(
    EntityModels::ListGroupBlocksRequest& request,
    ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupBlocks"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupBlocksResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnListGroupBlocksResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::ListGroupBlocksResponse* outResult = new EntityModels::ListGroupBlocksResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::ListGroupBlocksResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::ListGroupBlocksResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ListGroupInvitations(
    EntityModels::ListGroupInvitationsRequest& request,
    ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupInvitations"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupInvitationsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnListGroupInvitationsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::ListGroupInvitationsResponse* outResult = new EntityModels::ListGroupInvitationsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::ListGroupInvitationsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ListGroupMembers(
    EntityModels::ListGroupMembersRequest& request,
    ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnListGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::ListGroupMembersResponse* outResult = new EntityModels::ListGroupMembersResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::ListGroupMembersResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::ListGroupMembersResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ListMembership(
    EntityModels::ListMembershipRequest& request,
    ProcessApiCallback<EntityModels::ListMembershipResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListMembership"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListMembershipResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnListMembershipResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::ListMembershipResponse* outResult = new EntityModels::ListMembershipResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::ListMembershipResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::ListMembershipResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::ListMembershipOpportunities(
    EntityModels::ListMembershipOpportunitiesRequest& request,
    ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListMembershipOpportunities"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListMembershipOpportunitiesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnListMembershipOpportunitiesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::ListMembershipOpportunitiesResponse* outResult = new EntityModels::ListMembershipOpportunitiesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::RemoveGroupApplication(
    EntityModels::RemoveGroupApplicationRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/RemoveGroupApplication"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRemoveGroupApplicationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnRemoveGroupApplicationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::RemoveGroupInvitation(
    EntityModels::RemoveGroupInvitationRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/RemoveGroupInvitation"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRemoveGroupInvitationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnRemoveGroupInvitationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::RemoveMembers(
    EntityModels::RemoveMembersRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/RemoveMembers"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRemoveMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnRemoveMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::SetGlobalPolicy(
    EntityModels::SetGlobalPolicyRequest& request,
    ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/SetGlobalPolicy"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSetGlobalPolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnSetGlobalPolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::SetGlobalPolicyResponse* outResult = new EntityModels::SetGlobalPolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::SetGlobalPolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::SetObjects(
    EntityModels::SetObjectsRequest& request,
    ProcessApiCallback<EntityModels::SetObjectsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Object/SetObjects"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSetObjectsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnSetObjectsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::SetObjectsResponse* outResult = new EntityModels::SetObjectsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::SetObjectsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::SetObjectsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::SetProfilePolicy(
    EntityModels::SetEntityProfilePolicyRequest& request,
    ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Profile/SetProfilePolicy"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSetProfilePolicyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnSetProfilePolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::SetEntityProfilePolicyResponse* outResult = new EntityModels::SetEntityProfilePolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::UnblockEntity(
    EntityModels::UnblockEntityRequest& request,
    ProcessApiCallback<EntityModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/UnblockEntity"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnUnblockEntityResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnUnblockEntityResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::EmptyResult* outResult = new EntityModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::UpdateGroup(
    EntityModels::UpdateGroupRequest& request,
    ProcessApiCallback<EntityModels::UpdateGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/UpdateGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnUpdateGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnUpdateGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::UpdateGroupResponse* outResult = new EntityModels::UpdateGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::UpdateGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::UpdateGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabEntityApi::UpdateRole(
    EntityModels::UpdateGroupRoleRequest& request,
    ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/UpdateRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnUpdateRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEntityApi::OnUpdateRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EntityModels::UpdateGroupRoleResponse* outResult = new EntityModels::UpdateGroupRoleResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> successCallback = reinterpret_cast<ProcessApiCallback<EntityModels::UpdateGroupRoleResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

