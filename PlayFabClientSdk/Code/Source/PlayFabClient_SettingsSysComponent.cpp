
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_SettingsSysComponent.h"

#include "PlayFabSettings.h"

namespace PlayFabClientSdk
{
    void PlayFabClient_SettingsSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClient_SettingsSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClient_SettingsSysComponent>("PlayFabClient_Settings", "Provides access to the Settings API within the PlayFab Client SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClient_SettingsSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClient_SettingsService"));
    }

    void PlayFabClient_SettingsSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClient_SettingsService"));
    }

    void PlayFabClient_SettingsSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClient_SettingsSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClient_SettingsSysComponent::Init()
    {
    }

    void PlayFabClient_SettingsSysComponent::Activate()
    {
        PlayFabClient_SettingsRequestBus::Handler::BusConnect();
    }

    void PlayFabClient_SettingsSysComponent::Deactivate()
    {
        PlayFabClient_SettingsRequestBus::Handler::BusDisconnect();
    }
    
    // Read-Only Section
    AZStd::string PlayFabClient_SettingsSysComponent::GetBuildIdentifier()
    {
        return PlayFabSettings::playFabSettings->buildIdentifier;
    }

    // Read/Write Section
    void PlayFabClient_SettingsSysComponent::SetTitleId(AZStd::string newTitleId)
    {
        PlayFabSettings::playFabSettings->titleId = newTitleId;
    }

    AZStd::string PlayFabClient_SettingsSysComponent::GetTitleId()
    {
        return PlayFabSettings::playFabSettings->titleId;
    }

}
