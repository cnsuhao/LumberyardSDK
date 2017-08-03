
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabClientSdk//PlayFabClient_SettingsBus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_SettingsSysComponent
        : public AZ::Component
        , protected PlayFabClient_SettingsRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabClient_SettingsSysComponent, "{FDEEA325-EC4C-4D4B-9FBD-E64A8D523CE0}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);
        
        // Read-Only Section
        AZStd::string GetBuildIdentifier() override;

        // Read/Write Section
        void SetTitleId(AZStd::string newTitleId) override;
        AZStd::string GetTitleId() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
