
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_SettingsSysComponent.h"

#include "PlayFabSettings.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_SettingsSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_SettingsSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_SettingsSysComponent>("PlayFabCombo_Settings", "Provides access to the Settings API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_SettingsSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_SettingsService"));
    }

    void PlayFabCombo_SettingsSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_SettingsService"));
    }

    void PlayFabCombo_SettingsSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_SettingsSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_SettingsSysComponent::Init()
    {
    }

    void PlayFabCombo_SettingsSysComponent::Activate()
    {
        PlayFabCombo_SettingsRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_SettingsSysComponent::Deactivate()
    {
        PlayFabCombo_SettingsRequestBus::Handler::BusDisconnect();
    }
    
    // Read-Only Section
    AZStd::string PlayFabCombo_SettingsSysComponent::GetBuildIdentifier()
    {
        return PlayFabSettings::playFabSettings->buildIdentifier;
    }

    // Read/Write Section
    void PlayFabCombo_SettingsSysComponent::SetTitleId(AZStd::string newTitleId)
    {
        PlayFabSettings::playFabSettings->titleId = newTitleId;
    }

    AZStd::string PlayFabCombo_SettingsSysComponent::GetTitleId()
    {
        return PlayFabSettings::playFabSettings->titleId;
    }

    void PlayFabCombo_SettingsSysComponent::SetDevSecretKey(AZStd::string newSecretKey)
    {
        PlayFabSettings::playFabSettings->developerSecretKey = newSecretKey;
    }

    AZStd::string PlayFabCombo_SettingsSysComponent::GetDevSecretKey()
    {
        return PlayFabSettings::playFabSettings->developerSecretKey;
    }

}
