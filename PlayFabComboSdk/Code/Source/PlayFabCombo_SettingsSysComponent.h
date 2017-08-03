
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk//PlayFabCombo_SettingsBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_SettingsSysComponent
        : public AZ::Component
        , protected PlayFabCombo_SettingsRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_SettingsSysComponent, "{525A86F9-CFF4-4868-A55F-24F5E76823C0}");

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

        void SetDevSecretKey(AZStd::string newSecretKey) override;
        AZStd::string GetDevSecretKey() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
