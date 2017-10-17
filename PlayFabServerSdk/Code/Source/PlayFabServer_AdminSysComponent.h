
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabServerSdk/PlayFabServer_AdminBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServer_AdminSysComponent
        : public AZ::Component
        , protected PlayFabServer_AdminRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabServer_AdminSysComponent, "{9C3DF7E4-CCFD-42F4-9B75-0B9DF489456D}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabServer_AdminRequestBus interface implementation

        // ------------ Generated Api calls
        void AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreatePlayerSharedSecret(AdminModels::CreatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeletePlayer(AdminModels::DeletePlayerRequest& request, ProcessApiCallback<AdminModels::DeletePlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeletePlayerSharedSecret(AdminModels::DeletePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetAllSegments(ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCloudScriptVersions(ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerSharedSecrets(ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatisticDefinitions(ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPolicy(AdminModels::GetPolicyRequest& request, ProcessApiCallback<AdminModels::GetPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTaskInstances(AdminModels::GetTaskInstancesRequest& request, ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTasks(AdminModels::GetTasksRequest& request, ProcessApiCallback<AdminModels::GetTasksResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListServerBuilds(ProcessApiCallback<AdminModels::ListBuildsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ListVirtualCurrencyTypes(ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RunTask(AdminModels::RunTaskRequest& request, ProcessApiCallback<AdminModels::RunTaskResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetPlayerSecret(AdminModels::SetPlayerSecretRequest& request, ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdatePlayerSharedSecret(AdminModels::UpdatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdatePolicy(AdminModels::UpdatePolicyRequest& request, ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
