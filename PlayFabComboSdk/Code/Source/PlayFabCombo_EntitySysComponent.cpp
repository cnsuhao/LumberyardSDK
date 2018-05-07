
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_EntitySysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabEntityApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_EntitySysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_EntitySysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_EntitySysComponent>("PlayFabCombo_Entity", "Provides access to the Entity API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_EntitySysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_EntityService"));
    }

    void PlayFabCombo_EntitySysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_EntityService"));
    }

    void PlayFabCombo_EntitySysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_EntitySysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_EntitySysComponent::Init()
    {
    }

    void PlayFabCombo_EntitySysComponent::Activate()
    {
        PlayFabCombo_EntityRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_EntitySysComponent::Deactivate()
    {
        PlayFabCombo_EntityRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_EntitySysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_EntitySysComponent::AbortFileUploads(EntityModels::AbortFileUploadsRequest& request, ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AbortFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::AcceptGroupApplication(EntityModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AcceptGroupApplication(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::AcceptGroupInvitation(EntityModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AcceptGroupInvitation(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::AddMembers(EntityModels::AddMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AddMembers(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ApplyToGroup(EntityModels::ApplyToGroupRequest& request, ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ApplyToGroup(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::BlockEntity(EntityModels::BlockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::BlockEntity(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ChangeMemberRole(EntityModels::ChangeMemberRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ChangeMemberRole(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::CreateGroup(EntityModels::CreateGroupRequest& request, ProcessApiCallback<EntityModels::CreateGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::CreateGroup(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::CreateRole(EntityModels::CreateGroupRoleRequest& request, ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::CreateRole(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::DeleteFiles(EntityModels::DeleteFilesRequest& request, ProcessApiCallback<EntityModels::DeleteFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::DeleteFiles(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::DeleteGroup(EntityModels::DeleteGroupRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::DeleteGroup(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::DeleteRole(EntityModels::DeleteRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::DeleteRole(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::FinalizeFileUploads(EntityModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::FinalizeFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::GetEntityToken(EntityModels::GetEntityTokenRequest& request, ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetEntityToken(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::GetFiles(EntityModels::GetFilesRequest& request, ProcessApiCallback<EntityModels::GetFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetFiles(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::GetGlobalPolicy(ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetGlobalPolicy(callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::GetGroup(EntityModels::GetGroupRequest& request, ProcessApiCallback<EntityModels::GetGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetGroup(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::GetObjects(EntityModels::GetObjectsRequest& request, ProcessApiCallback<EntityModels::GetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetObjects(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::GetProfile(EntityModels::GetEntityProfileRequest& request, ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetProfile(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::GetProfiles(EntityModels::GetEntityProfilesRequest& request, ProcessApiCallback<EntityModels::GetEntityProfilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetProfiles(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::InitiateFileUploads(EntityModels::InitiateFileUploadsRequest& request, ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::InitiateFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::InviteToGroup(EntityModels::InviteToGroupRequest& request, ProcessApiCallback<EntityModels::InviteToGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::InviteToGroup(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::IsMember(EntityModels::IsMemberRequest& request, ProcessApiCallback<EntityModels::IsMemberResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::IsMember(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ListGroupApplications(EntityModels::ListGroupApplicationsRequest& request, ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupApplications(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ListGroupBlocks(EntityModels::ListGroupBlocksRequest& request, ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupBlocks(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ListGroupInvitations(EntityModels::ListGroupInvitationsRequest& request, ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupInvitations(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ListGroupMembers(EntityModels::ListGroupMembersRequest& request, ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ListMembership(EntityModels::ListMembershipRequest& request, ProcessApiCallback<EntityModels::ListMembershipResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListMembership(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::ListMembershipOpportunities(EntityModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListMembershipOpportunities(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::RemoveGroupApplication(EntityModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::RemoveGroupApplication(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::RemoveGroupInvitation(EntityModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::RemoveGroupInvitation(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::RemoveMembers(EntityModels::RemoveMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::RemoveMembers(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::SetGlobalPolicy(EntityModels::SetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::SetGlobalPolicy(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::SetObjects(EntityModels::SetObjectsRequest& request, ProcessApiCallback<EntityModels::SetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::SetObjects(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::SetProfilePolicy(EntityModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::SetProfilePolicy(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::UnblockEntity(EntityModels::UnblockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::UnblockEntity(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::UpdateGroup(EntityModels::UpdateGroupRequest& request, ProcessApiCallback<EntityModels::UpdateGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::UpdateGroup(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_EntitySysComponent::UpdateRole(EntityModels::UpdateGroupRoleRequest& request, ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::UpdateRole(request, callback, errorCallback, customData);
    }
}
