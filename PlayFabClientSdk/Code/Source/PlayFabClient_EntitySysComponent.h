
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabClientSdk/PlayFabClient_EntityBus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_EntitySysComponent
        : public AZ::Component
        , protected PlayFabClient_EntityRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabClient_EntitySysComponent, "{}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabClient_EntityRequestBus interface implementation

        // ------------ Generated Api calls
        void AbortFileUploads(EntityModels::AbortFileUploadsRequest& request, ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AcceptGroupApplication(EntityModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AcceptGroupInvitation(EntityModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddMembers(EntityModels::AddMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ApplyToGroup(EntityModels::ApplyToGroupRequest& request, ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void BlockEntity(EntityModels::BlockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ChangeMemberRole(EntityModels::ChangeMemberRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateGroup(EntityModels::CreateGroupRequest& request, ProcessApiCallback<EntityModels::CreateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateRole(EntityModels::CreateGroupRoleRequest& request, ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteFiles(EntityModels::DeleteFilesRequest& request, ProcessApiCallback<EntityModels::DeleteFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteGroup(EntityModels::DeleteGroupRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteRole(EntityModels::DeleteRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void FinalizeFileUploads(EntityModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetEntityToken(EntityModels::GetEntityTokenRequest& request, ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFiles(EntityModels::GetFilesRequest& request, ProcessApiCallback<EntityModels::GetFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetGlobalPolicy(ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetGroup(EntityModels::GetGroupRequest& request, ProcessApiCallback<EntityModels::GetGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetObjects(EntityModels::GetObjectsRequest& request, ProcessApiCallback<EntityModels::GetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetProfile(EntityModels::GetEntityProfileRequest& request, ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetProfiles(EntityModels::GetEntityProfilesRequest& request, ProcessApiCallback<EntityModels::GetEntityProfilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void InitiateFileUploads(EntityModels::InitiateFileUploadsRequest& request, ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void InviteToGroup(EntityModels::InviteToGroupRequest& request, ProcessApiCallback<EntityModels::InviteToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void IsMember(EntityModels::IsMemberRequest& request, ProcessApiCallback<EntityModels::IsMemberResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupApplications(EntityModels::ListGroupApplicationsRequest& request, ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupBlocks(EntityModels::ListGroupBlocksRequest& request, ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupInvitations(EntityModels::ListGroupInvitationsRequest& request, ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupMembers(EntityModels::ListGroupMembersRequest& request, ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListMembership(EntityModels::ListMembershipRequest& request, ProcessApiCallback<EntityModels::ListMembershipResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListMembershipOpportunities(EntityModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveGroupApplication(EntityModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveGroupInvitation(EntityModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveMembers(EntityModels::RemoveMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetGlobalPolicy(EntityModels::SetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetObjects(EntityModels::SetObjectsRequest& request, ProcessApiCallback<EntityModels::SetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetProfilePolicy(EntityModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnblockEntity(EntityModels::UnblockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateGroup(EntityModels::UpdateGroupRequest& request, ProcessApiCallback<EntityModels::UpdateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateRole(EntityModels::UpdateGroupRoleRequest& request, ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
