#include "StdAfx.h"
#include "PlayFabGroupsApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabComboSdk;

// PlayFabGroups Api
PlayFabGroupsApi::PlayFabGroupsApi() {}

void PlayFabGroupsApi::AcceptGroupApplication(
    GroupsModels::AcceptGroupApplicationRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/AcceptGroupApplication"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAcceptGroupApplicationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnAcceptGroupApplicationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::AcceptGroupInvitation(
    GroupsModels::AcceptGroupInvitationRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/AcceptGroupInvitation"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAcceptGroupInvitationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnAcceptGroupInvitationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::AddMembers(
    GroupsModels::AddMembersRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/AddMembers"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnAddMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnAddMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ApplyToGroup(
    GroupsModels::ApplyToGroupRequest& request,
    ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ApplyToGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnApplyToGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnApplyToGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::ApplyToGroupResponse* outResult = new GroupsModels::ApplyToGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::ApplyToGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::ApplyToGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::BlockEntity(
    GroupsModels::BlockEntityRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/BlockEntity"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnBlockEntityResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnBlockEntityResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ChangeMemberRole(
    GroupsModels::ChangeMemberRoleRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ChangeMemberRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnChangeMemberRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnChangeMemberRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::CreateGroup(
    GroupsModels::CreateGroupRequest& request,
    ProcessApiCallback<GroupsModels::CreateGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/CreateGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnCreateGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnCreateGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::CreateGroupResponse* outResult = new GroupsModels::CreateGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::CreateGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::CreateGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::CreateRole(
    GroupsModels::CreateGroupRoleRequest& request,
    ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/CreateRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnCreateRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnCreateRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::CreateGroupRoleResponse* outResult = new GroupsModels::CreateGroupRoleResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::CreateGroupRoleResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::DeleteGroup(
    GroupsModels::DeleteGroupRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/DeleteGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnDeleteGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnDeleteGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::DeleteRole(
    GroupsModels::DeleteRoleRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/DeleteRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnDeleteRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnDeleteRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::GetGroup(
    GroupsModels::GetGroupRequest& request,
    ProcessApiCallback<GroupsModels::GetGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/GetGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnGetGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::GetGroupResponse* outResult = new GroupsModels::GetGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::GetGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::GetGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::InviteToGroup(
    GroupsModels::InviteToGroupRequest& request,
    ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/InviteToGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnInviteToGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnInviteToGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::InviteToGroupResponse* outResult = new GroupsModels::InviteToGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::InviteToGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::InviteToGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::IsMember(
    GroupsModels::IsMemberRequest& request,
    ProcessApiCallback<GroupsModels::IsMemberResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/IsMember"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnIsMemberResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnIsMemberResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::IsMemberResponse* outResult = new GroupsModels::IsMemberResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::IsMemberResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::IsMemberResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ListGroupApplications(
    GroupsModels::ListGroupApplicationsRequest& request,
    ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupApplications"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupApplicationsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnListGroupApplicationsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::ListGroupApplicationsResponse* outResult = new GroupsModels::ListGroupApplicationsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ListGroupBlocks(
    GroupsModels::ListGroupBlocksRequest& request,
    ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupBlocks"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupBlocksResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnListGroupBlocksResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::ListGroupBlocksResponse* outResult = new GroupsModels::ListGroupBlocksResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::ListGroupBlocksResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ListGroupInvitations(
    GroupsModels::ListGroupInvitationsRequest& request,
    ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupInvitations"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupInvitationsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnListGroupInvitationsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::ListGroupInvitationsResponse* outResult = new GroupsModels::ListGroupInvitationsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ListGroupMembers(
    GroupsModels::ListGroupMembersRequest& request,
    ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListGroupMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnListGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::ListGroupMembersResponse* outResult = new GroupsModels::ListGroupMembersResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::ListGroupMembersResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::ListGroupMembersResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ListMembership(
    GroupsModels::ListMembershipRequest& request,
    ProcessApiCallback<GroupsModels::ListMembershipResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListMembership"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListMembershipResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnListMembershipResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::ListMembershipResponse* outResult = new GroupsModels::ListMembershipResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::ListMembershipResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::ListMembershipResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::ListMembershipOpportunities(
    GroupsModels::ListMembershipOpportunitiesRequest& request,
    ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/ListMembershipOpportunities"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnListMembershipOpportunitiesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnListMembershipOpportunitiesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::ListMembershipOpportunitiesResponse* outResult = new GroupsModels::ListMembershipOpportunitiesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::RemoveGroupApplication(
    GroupsModels::RemoveGroupApplicationRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/RemoveGroupApplication"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRemoveGroupApplicationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnRemoveGroupApplicationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::RemoveGroupInvitation(
    GroupsModels::RemoveGroupInvitationRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/RemoveGroupInvitation"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRemoveGroupInvitationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnRemoveGroupInvitationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::RemoveMembers(
    GroupsModels::RemoveMembersRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/RemoveMembers"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRemoveMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnRemoveMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::UnblockEntity(
    GroupsModels::UnblockEntityRequest& request,
    ProcessApiCallback<GroupsModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/UnblockEntity"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnUnblockEntityResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnUnblockEntityResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::EmptyResult* outResult = new GroupsModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::UpdateGroup(
    GroupsModels::UpdateGroupRequest& request,
    ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/UpdateGroup"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnUpdateGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnUpdateGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::UpdateGroupResponse* outResult = new GroupsModels::UpdateGroupResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::UpdateGroupResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::UpdateGroupResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabGroupsApi::UpdateRole(
    GroupsModels::UpdateGroupRoleRequest& request,
    ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Group/UpdateRole"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnUpdateRoleResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabGroupsApi::OnUpdateRoleResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        GroupsModels::UpdateGroupRoleResponse* outResult = new GroupsModels::UpdateGroupRoleResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> successCallback = reinterpret_cast<ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

