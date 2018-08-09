
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_GroupsSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabGroupsApi.h"

namespace PlayFabClientSdk
{
    void PlayFabClient_GroupsSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClient_GroupsSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClient_GroupsSysComponent>("PlayFabClient_Groups", "Provides access to the Groups API within the PlayFab Client SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClient_GroupsSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClient_GroupsService"));
    }

    void PlayFabClient_GroupsSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClient_GroupsService"));
    }

    void PlayFabClient_GroupsSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClient_GroupsSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClient_GroupsSysComponent::Init()
    {
    }

    void PlayFabClient_GroupsSysComponent::Activate()
    {
        PlayFabClient_GroupsRequestBus::Handler::BusConnect();
    }

    void PlayFabClient_GroupsSysComponent::Deactivate()
    {
        PlayFabClient_GroupsRequestBus::Handler::BusDisconnect();
    }

    int PlayFabClient_GroupsSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabClient_GroupsSysComponent::AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::AcceptGroupApplication(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::AcceptGroupInvitation(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::AddMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ApplyToGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::BlockEntity(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ChangeMemberRole(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::CreateGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::CreateRole(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::DeleteGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::DeleteRole(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::GetGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::InviteToGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::IsMember(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ListGroupApplications(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ListGroupBlocks(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ListGroupInvitations(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ListGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ListMembership(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::ListMembershipOpportunities(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::RemoveGroupApplication(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::RemoveGroupInvitation(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::RemoveMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::UnblockEntity(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::UpdateGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_GroupsSysComponent::UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabGroupsApi::UpdateRole(request, callback, errorCallback, customData);
    }
}
