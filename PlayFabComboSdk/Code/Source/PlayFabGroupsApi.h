#pragma once

#include <PlayFabComboSdk/PlayFabError.h>
#include <PlayFabComboSdk/PlayFabGroupsDataModels.h>
#include <PlayFabComboSdk/PlayFabHttp.h>

namespace PlayFabComboSdk
{
    class PlayFabGroupsApi
    {
    public:

        // ------------ Generated Api calls
        static void AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabGroupsApi();

        // ------------ Generated result handlers
        static void OnAcceptGroupApplicationResult(PlayFabRequest* request);
        static void OnAcceptGroupInvitationResult(PlayFabRequest* request);
        static void OnAddMembersResult(PlayFabRequest* request);
        static void OnApplyToGroupResult(PlayFabRequest* request);
        static void OnBlockEntityResult(PlayFabRequest* request);
        static void OnChangeMemberRoleResult(PlayFabRequest* request);
        static void OnCreateGroupResult(PlayFabRequest* request);
        static void OnCreateRoleResult(PlayFabRequest* request);
        static void OnDeleteGroupResult(PlayFabRequest* request);
        static void OnDeleteRoleResult(PlayFabRequest* request);
        static void OnGetGroupResult(PlayFabRequest* request);
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
        static void OnUnblockEntityResult(PlayFabRequest* request);
        static void OnUpdateGroupResult(PlayFabRequest* request);
        static void OnUpdateRoleResult(PlayFabRequest* request);
    };
};
