
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_EntitySysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabEntityApi.h"

namespace PlayFabClientSdk
{
    void PlayFabClient_EntitySysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClient_EntitySysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClient_EntitySysComponent>("PlayFabClient_Entity", "Provides access to the Entity API within the PlayFab Client SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClient_EntitySysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClient_EntityService"));
    }

    void PlayFabClient_EntitySysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClient_EntityService"));
    }

    void PlayFabClient_EntitySysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClient_EntitySysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClient_EntitySysComponent::Init()
    {
    }

    void PlayFabClient_EntitySysComponent::Activate()
    {
        PlayFabClient_EntityRequestBus::Handler::BusConnect();
    }

    void PlayFabClient_EntitySysComponent::Deactivate()
    {
        PlayFabClient_EntityRequestBus::Handler::BusDisconnect();
    }

    int PlayFabClient_EntitySysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabClient_EntitySysComponent::AbortFileUploads(EntityModels::AbortFileUploadsRequest& request, ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AbortFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::AcceptGroupApplication(EntityModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AcceptGroupApplication(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::AcceptGroupInvitation(EntityModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AcceptGroupInvitation(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::AddMembers(EntityModels::AddMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::AddMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ApplyToGroup(EntityModels::ApplyToGroupRequest& request, ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ApplyToGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::BlockEntity(EntityModels::BlockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::BlockEntity(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ChangeMemberRole(EntityModels::ChangeMemberRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ChangeMemberRole(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::CreateGroup(EntityModels::CreateGroupRequest& request, ProcessApiCallback<EntityModels::CreateGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::CreateGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::CreateRole(EntityModels::CreateGroupRoleRequest& request, ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::CreateRole(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::DeleteFiles(EntityModels::DeleteFilesRequest& request, ProcessApiCallback<EntityModels::DeleteFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::DeleteFiles(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::DeleteGroup(EntityModels::DeleteGroupRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::DeleteGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::DeleteRole(EntityModels::DeleteRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::DeleteRole(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ExecuteEntityCloudScript(EntityModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<EntityModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ExecuteEntityCloudScript(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::FinalizeFileUploads(EntityModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::FinalizeFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::GetEntityToken(EntityModels::GetEntityTokenRequest& request, ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetEntityToken(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::GetFiles(EntityModels::GetFilesRequest& request, ProcessApiCallback<EntityModels::GetFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetFiles(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::GetGlobalPolicy(ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetGlobalPolicy(callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::GetGroup(EntityModels::GetGroupRequest& request, ProcessApiCallback<EntityModels::GetGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::GetObjects(EntityModels::GetObjectsRequest& request, ProcessApiCallback<EntityModels::GetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetObjects(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::GetProfile(EntityModels::GetEntityProfileRequest& request, ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetProfile(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::GetProfiles(EntityModels::GetEntityProfilesRequest& request, ProcessApiCallback<EntityModels::GetEntityProfilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::GetProfiles(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::InitiateFileUploads(EntityModels::InitiateFileUploadsRequest& request, ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::InitiateFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::InviteToGroup(EntityModels::InviteToGroupRequest& request, ProcessApiCallback<EntityModels::InviteToGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::InviteToGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::IsMember(EntityModels::IsMemberRequest& request, ProcessApiCallback<EntityModels::IsMemberResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::IsMember(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ListGroupApplications(EntityModels::ListGroupApplicationsRequest& request, ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupApplications(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ListGroupBlocks(EntityModels::ListGroupBlocksRequest& request, ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupBlocks(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ListGroupInvitations(EntityModels::ListGroupInvitationsRequest& request, ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupInvitations(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ListGroupMembers(EntityModels::ListGroupMembersRequest& request, ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ListMembership(EntityModels::ListMembershipRequest& request, ProcessApiCallback<EntityModels::ListMembershipResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListMembership(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::ListMembershipOpportunities(EntityModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::ListMembershipOpportunities(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::RemoveGroupApplication(EntityModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::RemoveGroupApplication(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::RemoveGroupInvitation(EntityModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::RemoveGroupInvitation(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::RemoveMembers(EntityModels::RemoveMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::RemoveMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::SetGlobalPolicy(EntityModels::SetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::SetGlobalPolicy(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::SetObjects(EntityModels::SetObjectsRequest& request, ProcessApiCallback<EntityModels::SetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::SetObjects(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::SetProfilePolicy(EntityModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::SetProfilePolicy(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::UnblockEntity(EntityModels::UnblockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::UnblockEntity(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::UpdateGroup(EntityModels::UpdateGroupRequest& request, ProcessApiCallback<EntityModels::UpdateGroupResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::UpdateGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::UpdateRole(EntityModels::UpdateGroupRoleRequest& request, ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::UpdateRole(request, callback, errorCallback, customData);
    }
    void PlayFabClient_EntitySysComponent::WriteEvents(EntityModels::WriteEventsRequest& request, ProcessApiCallback<EntityModels::WriteEventsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEntityApi::WriteEvents(request, callback, errorCallback, customData);
    }
}
