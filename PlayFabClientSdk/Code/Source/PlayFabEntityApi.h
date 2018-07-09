#pragma once

#include <PlayFabClientSdk/PlayFabError.h>
#include <PlayFabClientSdk/PlayFabEntityDataModels.h>
#include <PlayFabClientSdk/PlayFabHttp.h>

namespace PlayFabClientSdk
{
    class PlayFabEntityApi
    {
    public:

        // ------------ Generated Api calls
        static void AbortFileUploads(EntityModels::AbortFileUploadsRequest& request, ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupApplication(EntityModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupInvitation(EntityModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddMembers(EntityModels::AddMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ApplyToGroup(EntityModels::ApplyToGroupRequest& request, ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BlockEntity(EntityModels::BlockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ChangeMemberRole(EntityModels::ChangeMemberRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateGroup(EntityModels::CreateGroupRequest& request, ProcessApiCallback<EntityModels::CreateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRole(EntityModels::CreateGroupRoleRequest& request, ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteFiles(EntityModels::DeleteFilesRequest& request, ProcessApiCallback<EntityModels::DeleteFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteGroup(EntityModels::DeleteGroupRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRole(EntityModels::DeleteRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteEntityCloudScript(EntityModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<EntityModels::ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void FinalizeFileUploads(EntityModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityToken(EntityModels::GetEntityTokenRequest& request, ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFiles(EntityModels::GetFilesRequest& request, ProcessApiCallback<EntityModels::GetFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGlobalPolicy(ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGroup(EntityModels::GetGroupRequest& request, ProcessApiCallback<EntityModels::GetGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetObjects(EntityModels::GetObjectsRequest& request, ProcessApiCallback<EntityModels::GetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetProfile(EntityModels::GetEntityProfileRequest& request, ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetProfiles(EntityModels::GetEntityProfilesRequest& request, ProcessApiCallback<EntityModels::GetEntityProfilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InitiateFileUploads(EntityModels::InitiateFileUploadsRequest& request, ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InviteToGroup(EntityModels::InviteToGroupRequest& request, ProcessApiCallback<EntityModels::InviteToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IsMember(EntityModels::IsMemberRequest& request, ProcessApiCallback<EntityModels::IsMemberResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupApplications(EntityModels::ListGroupApplicationsRequest& request, ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupBlocks(EntityModels::ListGroupBlocksRequest& request, ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupInvitations(EntityModels::ListGroupInvitationsRequest& request, ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupMembers(EntityModels::ListGroupMembersRequest& request, ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembership(EntityModels::ListMembershipRequest& request, ProcessApiCallback<EntityModels::ListMembershipResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembershipOpportunities(EntityModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupApplication(EntityModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupInvitation(EntityModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMembers(EntityModels::RemoveMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGlobalPolicy(EntityModels::SetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetObjects(EntityModels::SetObjectsRequest& request, ProcessApiCallback<EntityModels::SetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetProfilePolicy(EntityModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnblockEntity(EntityModels::UnblockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateGroup(EntityModels::UpdateGroupRequest& request, ProcessApiCallback<EntityModels::UpdateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRole(EntityModels::UpdateGroupRoleRequest& request, ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteEvents(EntityModels::WriteEventsRequest& request, ProcessApiCallback<EntityModels::WriteEventsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabEntityApi();

        // ------------ Generated result handlers
        static void OnAbortFileUploadsResult(PlayFabRequest* request);
        static void OnAcceptGroupApplicationResult(PlayFabRequest* request);
        static void OnAcceptGroupInvitationResult(PlayFabRequest* request);
        static void OnAddMembersResult(PlayFabRequest* request);
        static void OnApplyToGroupResult(PlayFabRequest* request);
        static void OnBlockEntityResult(PlayFabRequest* request);
        static void OnChangeMemberRoleResult(PlayFabRequest* request);
        static void OnCreateGroupResult(PlayFabRequest* request);
        static void OnCreateRoleResult(PlayFabRequest* request);
        static void OnDeleteFilesResult(PlayFabRequest* request);
        static void OnDeleteGroupResult(PlayFabRequest* request);
        static void OnDeleteRoleResult(PlayFabRequest* request);
        static void OnExecuteEntityCloudScriptResult(PlayFabRequest* request);
        static void OnFinalizeFileUploadsResult(PlayFabRequest* request);
        static void OnGetEntityTokenResult(PlayFabRequest* request);
        static void OnGetFilesResult(PlayFabRequest* request);
        static void OnGetGlobalPolicyResult(PlayFabRequest* request);
        static void OnGetGroupResult(PlayFabRequest* request);
        static void OnGetObjectsResult(PlayFabRequest* request);
        static void OnGetProfileResult(PlayFabRequest* request);
        static void OnGetProfilesResult(PlayFabRequest* request);
        static void OnInitiateFileUploadsResult(PlayFabRequest* request);
        static void OnInviteToGroupResult(PlayFabRequest* request);
        static void OnIsMemberResult(PlayFabRequest* request);
        static void OnListGroupApplicationsResult(PlayFabRequest* request);
        static void OnListGroupBlocksResult(PlayFabRequest* request);
        static void OnListGroupInvitationsResult(PlayFabRequest* request);
        static void OnListGroupMembersResult(PlayFabRequest* request);
        static void OnListMembershipResult(PlayFabRequest* request);
        static void OnListMembershipOpportunitiesResult(PlayFabRequest* request);
        static void OnRemoveGroupApplicationResult(PlayFabRequest* request);
        static void OnRemoveGroupInvitationResult(PlayFabRequest* request);
        static void OnRemoveMembersResult(PlayFabRequest* request);
        static void OnSetGlobalPolicyResult(PlayFabRequest* request);
        static void OnSetObjectsResult(PlayFabRequest* request);
        static void OnSetProfilePolicyResult(PlayFabRequest* request);
        static void OnUnblockEntityResult(PlayFabRequest* request);
        static void OnUpdateGroupResult(PlayFabRequest* request);
        static void OnUpdateRoleResult(PlayFabRequest* request);
        static void OnWriteEventsResult(PlayFabRequest* request);
    };
};
