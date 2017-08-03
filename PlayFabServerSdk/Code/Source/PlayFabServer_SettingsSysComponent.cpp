
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_SettingsSysComponent.h"

#include "PlayFabSettings.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_SettingsSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_SettingsSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_SettingsSysComponent>("PlayFabServer_Settings", "Provides access to the Settings API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_SettingsSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_SettingsService"));
    }

    void PlayFabServer_SettingsSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_SettingsService"));
    }

    void PlayFabServer_SettingsSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_SettingsSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_SettingsSysComponent::Init()
    {
    }

    void PlayFabServer_SettingsSysComponent::Activate()
    {
        PlayFabServer_SettingsRequestBus::Handler::BusConnect();
    }

    void PlayFabServer_SettingsSysComponent::Deactivate()
    {
        PlayFabServer_SettingsRequestBus::Handler::BusDisconnect();
    }
    
    // Read-Only Section
    AZStd::string PlayFabServer_SettingsSysComponent::GetBuildIdentifier()
    {
        return PlayFabSettings::playFabSettings->buildIdentifier;
    }

    // Read/Write Section
    void PlayFabServer_SettingsSysComponent::SetTitleId(AZStd::string newTitleId)
    {
        PlayFabSettings::playFabSettings->titleId = newTitleId;
    }

    AZStd::string PlayFabServer_SettingsSysComponent::GetTitleId()
    {
        return PlayFabSettings::playFabSettings->titleId;
    }

    void PlayFabServer_SettingsSysComponent::SetDevSecretKey(AZStd::string newSecretKey)
    {
        PlayFabSettings::playFabSettings->developerSecretKey = newSecretKey;
    }

    AZStd::string PlayFabServer_SettingsSysComponent::GetDevSecretKey()
    {
        return PlayFabSettings::playFabSettings->developerSecretKey;
    }

}
