
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_ProfilesSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabProfilesApi.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_ProfilesSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_ProfilesSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_ProfilesSysComponent>("PlayFabServer_Profiles", "Provides access to the Profiles API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_ProfilesSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_ProfilesService"));
    }

    void PlayFabServer_ProfilesSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_ProfilesService"));
    }

    void PlayFabServer_ProfilesSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_ProfilesSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_ProfilesSysComponent::Init()
    {
    }

    void PlayFabServer_ProfilesSysComponent::Activate()
    {
        PlayFabServer_ProfilesRequestBus::Handler::BusConnect();
    }

    void PlayFabServer_ProfilesSysComponent::Deactivate()
    {
        PlayFabServer_ProfilesRequestBus::Handler::BusDisconnect();
    }

    int PlayFabServer_ProfilesSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabServer_ProfilesSysComponent::GetGlobalPolicy(ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::GetGlobalPolicy(callback, errorCallback, customData);
    }
    void PlayFabServer_ProfilesSysComponent::GetProfile(ProfilesModels::GetEntityProfileRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::GetProfile(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ProfilesSysComponent::GetProfiles(ProfilesModels::GetEntityProfilesRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::GetProfiles(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ProfilesSysComponent::SetGlobalPolicy(ProfilesModels::SetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::SetGlobalPolicy(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ProfilesSysComponent::SetProfileLanguage(ProfilesModels::SetProfileLanguageRequest& request, ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::SetProfileLanguage(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ProfilesSysComponent::SetProfilePolicy(ProfilesModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::SetProfilePolicy(request, callback, errorCallback, customData);
    }
}
