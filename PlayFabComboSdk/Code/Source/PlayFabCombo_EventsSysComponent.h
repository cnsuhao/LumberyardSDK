
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabCombo_EventsBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_EventsSysComponent
        : public AZ::Component
        , protected PlayFabCombo_EventsRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_EventsSysComponent, "{}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabCombo_EventsRequestBus interface implementation

        // ------------ Generated Api calls
        void WriteEvents(EventsModels::WriteEventsRequest& request, ProcessApiCallback<EventsModels::WriteEventsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
