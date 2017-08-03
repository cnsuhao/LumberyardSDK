
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabServerSdk//PlayFabServer_SettingsBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServer_SettingsSysComponent
        : public AZ::Component
        , protected PlayFabServer_SettingsRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabServer_SettingsSysComponent, "{9C3DF7E4-CCFD-42F4-9B75-0B9DF4894560}");

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
