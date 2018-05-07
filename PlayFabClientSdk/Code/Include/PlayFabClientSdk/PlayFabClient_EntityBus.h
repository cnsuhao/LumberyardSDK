
#pragma once

#include <PlayFabClientSdk/PlayFabError.h>
#include <PlayFabClientSdk/PlayFabEntityDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_EntityRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual void AbortFileUploads(EntityModels::AbortFileUploadsRequest& request, ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AcceptGroupApplication(EntityModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AcceptGroupInvitation(EntityModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AddMembers(EntityModels::AddMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ApplyToGroup(EntityModels::ApplyToGroupRequest& request, ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void BlockEntity(EntityModels::BlockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ChangeMemberRole(EntityModels::ChangeMemberRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void CreateGroup(EntityModels::CreateGroupRequest& request, ProcessApiCallback<EntityModels::CreateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void CreateRole(EntityModels::CreateGroupRoleRequest& request, ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void DeleteFiles(EntityModels::DeleteFilesRequest& request, ProcessApiCallback<EntityModels::DeleteFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void DeleteGroup(EntityModels::DeleteGroupRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void DeleteRole(EntityModels::DeleteRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void FinalizeFileUploads(EntityModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetEntityToken(EntityModels::GetEntityTokenRequest& request, ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetFiles(EntityModels::GetFilesRequest& request, ProcessApiCallback<EntityModels::GetFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetGlobalPolicy(ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetGroup(EntityModels::GetGroupRequest& request, ProcessApiCallback<EntityModels::GetGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetObjects(EntityModels::GetObjectsRequest& request, ProcessApiCallback<EntityModels::GetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetProfile(EntityModels::GetEntityProfileRequest& request, ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetProfiles(EntityModels::GetEntityProfilesRequest& request, ProcessApiCallback<EntityModels::GetEntityProfilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void InitiateFileUploads(EntityModels::InitiateFileUploadsRequest& request, ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void InviteToGroup(EntityModels::InviteToGroupRequest& request, ProcessApiCallback<EntityModels::InviteToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void IsMember(EntityModels::IsMemberRequest& request, ProcessApiCallback<EntityModels::IsMemberResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ListGroupApplications(EntityModels::ListGroupApplicationsRequest& request, ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ListGroupBlocks(EntityModels::ListGroupBlocksRequest& request, ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ListGroupInvitations(EntityModels::ListGroupInvitationsRequest& request, ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ListGroupMembers(EntityModels::ListGroupMembersRequest& request, ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ListMembership(EntityModels::ListMembershipRequest& request, ProcessApiCallback<EntityModels::ListMembershipResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ListMembershipOpportunities(EntityModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RemoveGroupApplication(EntityModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RemoveGroupInvitation(EntityModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RemoveMembers(EntityModels::RemoveMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetGlobalPolicy(EntityModels::SetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetObjects(EntityModels::SetObjectsRequest& request, ProcessApiCallback<EntityModels::SetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetProfilePolicy(EntityModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnblockEntity(EntityModels::UnblockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateGroup(EntityModels::UpdateGroupRequest& request, ProcessApiCallback<EntityModels::UpdateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateRole(EntityModels::UpdateGroupRoleRequest& request, ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabClient_EntityRequestBus = AZ::EBus<PlayFabClient_EntityRequests>;
} // namespace PlayFabClientSdk
