
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabCombo_CloudScriptBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_CloudScriptSysComponent
        : public AZ::Component
        , protected PlayFabCombo_CloudScriptRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_CloudScriptSysComponent, "{}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabCombo_CloudScriptRequestBus interface implementation

        // ------------ Generated Api calls
        void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
