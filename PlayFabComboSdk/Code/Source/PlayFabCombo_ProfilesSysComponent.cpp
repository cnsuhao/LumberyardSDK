
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_ProfilesSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabProfilesApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_ProfilesSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_ProfilesSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_ProfilesSysComponent>("PlayFabCombo_Profiles", "Provides access to the Profiles API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_ProfilesSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_ProfilesService"));
    }

    void PlayFabCombo_ProfilesSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_ProfilesService"));
    }

    void PlayFabCombo_ProfilesSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_ProfilesSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_ProfilesSysComponent::Init()
    {
    }

    void PlayFabCombo_ProfilesSysComponent::Activate()
    {
        PlayFabCombo_ProfilesRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_ProfilesSysComponent::Deactivate()
    {
        PlayFabCombo_ProfilesRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_ProfilesSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_ProfilesSysComponent::GetGlobalPolicy(ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::GetGlobalPolicy(callback, errorCallback, customData);
    }
    void PlayFabCombo_ProfilesSysComponent::GetProfile(ProfilesModels::GetEntityProfileRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::GetProfile(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ProfilesSysComponent::GetProfiles(ProfilesModels::GetEntityProfilesRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::GetProfiles(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ProfilesSysComponent::SetGlobalPolicy(ProfilesModels::SetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::SetGlobalPolicy(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ProfilesSysComponent::SetProfileLanguage(ProfilesModels::SetProfileLanguageRequest& request, ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::SetProfileLanguage(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ProfilesSysComponent::SetProfilePolicy(ProfilesModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabProfilesApi::SetProfilePolicy(request, callback, errorCallback, customData);
    }
}
