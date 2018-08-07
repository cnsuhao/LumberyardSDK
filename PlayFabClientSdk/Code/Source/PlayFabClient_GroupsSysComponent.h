
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabClientSdk/PlayFabClient_GroupsBus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_GroupsSysComponent
        : public AZ::Component
        , protected PlayFabClient_GroupsRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabClient_GroupsSysComponent, "{}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabClient_GroupsRequestBus interface implementation

        // ------------ Generated Api calls
        void AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
