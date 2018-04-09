#pragma once

#include <PlayFabClientSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>

using namespace rapidjson;

namespace PlayFabClientSdk
{
    namespace ClientModels
    {
        struct AcceptTradeRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> AcceptedInventoryInstanceIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string OfferingPlayerId;
            AZStd::string TradeId;

            AcceptTradeRequest() :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(),
                OfferingPlayerId(),
                TradeId()
            {}

            AcceptTradeRequest(const AcceptTradeRequest& src) :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            AcceptTradeRequest(const rapidjson::Value& obj) : AcceptTradeRequest()
            {
                readFromValue(obj);
            }

            ~AcceptTradeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!AcceptedInventoryInstanceIds.empty()) {
                    writer.String("AcceptedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = AcceptedInventoryInstanceIds.begin(); iter != AcceptedInventoryInstanceIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.String("OfferingPlayerId");
                writer.String(OfferingPlayerId.c_str());
                writer.String("TradeId");
                writer.String(TradeId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AcceptedInventoryInstanceIds_member = obj.FindMember("AcceptedInventoryInstanceIds");
                if (AcceptedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AcceptedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AcceptedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
                if (OfferingPlayerId_member != obj.MemberEnd() && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

                return true;
            }
        };

        enum TradeStatus
        {
            TradeStatusInvalid,
            TradeStatusOpening,
            TradeStatusOpen,
            TradeStatusAccepting,
            TradeStatusAccepted,
            TradeStatusFilled,
            TradeStatusCancelled
        };

        inline void writeTradeStatusEnumJSON(TradeStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TradeStatusInvalid: writer.String("Invalid"); break;
            case TradeStatusOpening: writer.String("Opening"); break;
            case TradeStatusOpen: writer.String("Open"); break;
            case TradeStatusAccepting: writer.String("Accepting"); break;
            case TradeStatusAccepted: writer.String("Accepted"); break;
            case TradeStatusFilled: writer.String("Filled"); break;
            case TradeStatusCancelled: writer.String("Cancelled"); break;

            }
        }

        inline TradeStatus readTradeStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<TradeStatus>(obj.GetInt());

            static std::map<const char *, TradeStatus, PlayFabClientSdk::StringCompare> _TradeStatusMap;
            if (_TradeStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TradeStatusMap["Invalid"] = TradeStatusInvalid;
                _TradeStatusMap["Opening"] = TradeStatusOpening;
                _TradeStatusMap["Open"] = TradeStatusOpen;
                _TradeStatusMap["Accepting"] = TradeStatusAccepting;
                _TradeStatusMap["Accepted"] = TradeStatusAccepted;
                _TradeStatusMap["Filled"] = TradeStatusFilled;
                _TradeStatusMap["Cancelled"] = TradeStatusCancelled;

            }

            auto output = _TradeStatusMap.find(obj.GetString());
            if (output != _TradeStatusMap.end())
                return output->second;

            return TradeStatusInvalid; // Basically critical fail
        }

        struct TradeInfo : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> AcceptedInventoryInstanceIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string AcceptedPlayerId;
            AZStd::vector<AZStd::string> AllowedPlayerIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalTime CancelledAt;
            OptionalTime FilledAt;
            OptionalTime InvalidatedAt;
            AZStd::vector<AZStd::string> OfferedCatalogItemIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> OfferedInventoryInstanceIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string OfferingPlayerId;
            OptionalTime OpenedAt;
            AZStd::vector<AZStd::string> RequestedCatalogItemIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<TradeStatus> Status;
            AZStd::string TradeId;

            TradeInfo() :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(),
                AcceptedPlayerId(),
                AllowedPlayerIds(),
                CancelledAt(),
                FilledAt(),
                InvalidatedAt(),
                OfferedCatalogItemIds(),
                OfferedInventoryInstanceIds(),
                OfferingPlayerId(),
                OpenedAt(),
                RequestedCatalogItemIds(),
                Status(),
                TradeId()
            {}

            TradeInfo(const TradeInfo& src) :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                AcceptedPlayerId(src.AcceptedPlayerId),
                AllowedPlayerIds(src.AllowedPlayerIds),
                CancelledAt(src.CancelledAt),
                FilledAt(src.FilledAt),
                InvalidatedAt(src.InvalidatedAt),
                OfferedCatalogItemIds(src.OfferedCatalogItemIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                OpenedAt(src.OpenedAt),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                Status(src.Status),
                TradeId(src.TradeId)
            {}

            TradeInfo(const rapidjson::Value& obj) : TradeInfo()
            {
                readFromValue(obj);
            }

            ~TradeInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!AcceptedInventoryInstanceIds.empty()) {
                    writer.String("AcceptedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = AcceptedInventoryInstanceIds.begin(); iter != AcceptedInventoryInstanceIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (AcceptedPlayerId.length() > 0) {
                    writer.String("AcceptedPlayerId");
                    writer.String(AcceptedPlayerId.c_str());
                }
                if (!AllowedPlayerIds.empty()) {
                    writer.String("AllowedPlayerIds");
                    writer.StartArray();
                    for (auto iter = AllowedPlayerIds.begin(); iter != AllowedPlayerIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (CancelledAt.notNull()) {
                    writer.String("CancelledAt");
                    writeDatetime(CancelledAt, writer);
                }
                if (FilledAt.notNull()) {
                    writer.String("FilledAt");
                    writeDatetime(FilledAt, writer);
                }
                if (InvalidatedAt.notNull()) {
                    writer.String("InvalidatedAt");
                    writeDatetime(InvalidatedAt, writer);
                }
                if (!OfferedCatalogItemIds.empty()) {
                    writer.String("OfferedCatalogItemIds");
                    writer.StartArray();
                    for (auto iter = OfferedCatalogItemIds.begin(); iter != OfferedCatalogItemIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!OfferedInventoryInstanceIds.empty()) {
                    writer.String("OfferedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = OfferedInventoryInstanceIds.begin(); iter != OfferedInventoryInstanceIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (OfferingPlayerId.length() > 0) {
                    writer.String("OfferingPlayerId");
                    writer.String(OfferingPlayerId.c_str());
                }
                if (OpenedAt.notNull()) {
                    writer.String("OpenedAt");
                    writeDatetime(OpenedAt, writer);
                }
                if (!RequestedCatalogItemIds.empty()) {
                    writer.String("RequestedCatalogItemIds");
                    writer.StartArray();
                    for (auto iter = RequestedCatalogItemIds.begin(); iter != RequestedCatalogItemIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeTradeStatusEnumJSON(Status, writer);
                }
                if (TradeId.length() > 0) {
                    writer.String("TradeId");
                    writer.String(TradeId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AcceptedInventoryInstanceIds_member = obj.FindMember("AcceptedInventoryInstanceIds");
                if (AcceptedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AcceptedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AcceptedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator AcceptedPlayerId_member = obj.FindMember("AcceptedPlayerId");
                if (AcceptedPlayerId_member != obj.MemberEnd() && !AcceptedPlayerId_member->value.IsNull()) AcceptedPlayerId = AcceptedPlayerId_member->value.GetString();
                const Value::ConstMemberIterator AllowedPlayerIds_member = obj.FindMember("AllowedPlayerIds");
                if (AllowedPlayerIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AllowedPlayerIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AllowedPlayerIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator CancelledAt_member = obj.FindMember("CancelledAt");
                if (CancelledAt_member != obj.MemberEnd() && !CancelledAt_member->value.IsNull()) CancelledAt = readDatetime(CancelledAt_member->value);
                const Value::ConstMemberIterator FilledAt_member = obj.FindMember("FilledAt");
                if (FilledAt_member != obj.MemberEnd() && !FilledAt_member->value.IsNull()) FilledAt = readDatetime(FilledAt_member->value);
                const Value::ConstMemberIterator InvalidatedAt_member = obj.FindMember("InvalidatedAt");
                if (InvalidatedAt_member != obj.MemberEnd() && !InvalidatedAt_member->value.IsNull()) InvalidatedAt = readDatetime(InvalidatedAt_member->value);
                const Value::ConstMemberIterator OfferedCatalogItemIds_member = obj.FindMember("OfferedCatalogItemIds");
                if (OfferedCatalogItemIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OfferedCatalogItemIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OfferedCatalogItemIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator OfferedInventoryInstanceIds_member = obj.FindMember("OfferedInventoryInstanceIds");
                if (OfferedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OfferedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OfferedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
                if (OfferingPlayerId_member != obj.MemberEnd() && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
                const Value::ConstMemberIterator OpenedAt_member = obj.FindMember("OpenedAt");
                if (OpenedAt_member != obj.MemberEnd() && !OpenedAt_member->value.IsNull()) OpenedAt = readDatetime(OpenedAt_member->value);
                const Value::ConstMemberIterator RequestedCatalogItemIds_member = obj.FindMember("RequestedCatalogItemIds");
                if (RequestedCatalogItemIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = RequestedCatalogItemIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        RequestedCatalogItemIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTradeStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

                return true;
            }
        };

        struct AcceptTradeResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            AcceptTradeResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            AcceptTradeResponse(const AcceptTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            AcceptTradeResponse(const rapidjson::Value& obj) : AcceptTradeResponse()
            {
                readFromValue(obj);
            }

            ~AcceptTradeResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct AdCampaignAttributionModel : public PlayFabBaseModel
        {
            time_t AttributedAt;
            AZStd::string CampaignId;
            AZStd::string Platform;

            AdCampaignAttributionModel() :
                PlayFabBaseModel(),
                AttributedAt(0),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttributionModel(const AdCampaignAttributionModel& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            AdCampaignAttributionModel(const rapidjson::Value& obj) : AdCampaignAttributionModel()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttributionModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("AttributedAt");
                writeDatetime(AttributedAt, writer);
                if (CampaignId.length() > 0) {
                    writer.String("CampaignId");
                    writer.String(CampaignId.c_str());
                }
                if (Platform.length() > 0) {
                    writer.String("Platform");
                    writer.String(Platform.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AttributedAt_member = obj.FindMember("AttributedAt");
                if (AttributedAt_member != obj.MemberEnd() && !AttributedAt_member->value.IsNull()) AttributedAt = readDatetime(AttributedAt_member->value);
                const Value::ConstMemberIterator CampaignId_member = obj.FindMember("CampaignId");
                if (CampaignId_member != obj.MemberEnd() && !CampaignId_member->value.IsNull()) CampaignId = CampaignId_member->value.GetString();
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();

                return true;
            }
        };

        struct AddFriendRequest : public PlayFabBaseModel
        {
            AZStd::string FriendEmail;
            AZStd::string FriendPlayFabId;
            AZStd::string FriendTitleDisplayName;
            AZStd::string FriendUsername;

            AddFriendRequest() :
                PlayFabBaseModel(),
                FriendEmail(),
                FriendPlayFabId(),
                FriendTitleDisplayName(),
                FriendUsername()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabBaseModel(),
                FriendEmail(src.FriendEmail),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendTitleDisplayName(src.FriendTitleDisplayName),
                FriendUsername(src.FriendUsername)
            {}

            AddFriendRequest(const rapidjson::Value& obj) : AddFriendRequest()
            {
                readFromValue(obj);
            }

            ~AddFriendRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (FriendEmail.length() > 0) {
                    writer.String("FriendEmail");
                    writer.String(FriendEmail.c_str());
                }
                if (FriendPlayFabId.length() > 0) {
                    writer.String("FriendPlayFabId");
                    writer.String(FriendPlayFabId.c_str());
                }
                if (FriendTitleDisplayName.length() > 0) {
                    writer.String("FriendTitleDisplayName");
                    writer.String(FriendTitleDisplayName.c_str());
                }
                if (FriendUsername.length() > 0) {
                    writer.String("FriendUsername");
                    writer.String(FriendUsername.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendEmail_member = obj.FindMember("FriendEmail");
                if (FriendEmail_member != obj.MemberEnd() && !FriendEmail_member->value.IsNull()) FriendEmail = FriendEmail_member->value.GetString();
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator FriendTitleDisplayName_member = obj.FindMember("FriendTitleDisplayName");
                if (FriendTitleDisplayName_member != obj.MemberEnd() && !FriendTitleDisplayName_member->value.IsNull()) FriendTitleDisplayName = FriendTitleDisplayName_member->value.GetString();
                const Value::ConstMemberIterator FriendUsername_member = obj.FindMember("FriendUsername");
                if (FriendUsername_member != obj.MemberEnd() && !FriendUsername_member->value.IsNull()) FriendUsername = FriendUsername_member->value.GetString();

                return true;
            }
        };

        struct AddFriendResult : public PlayFabBaseModel
        {
            bool Created;

            AddFriendResult() :
                PlayFabBaseModel(),
                Created(false)
            {}

            AddFriendResult(const AddFriendResult& src) :
                PlayFabBaseModel(),
                Created(src.Created)
            {}

            AddFriendResult(const rapidjson::Value& obj) : AddFriendResult()
            {
                readFromValue(obj);
            }

            ~AddFriendResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Created");
                writer.Bool(Created);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = Created_member->value.GetBool();

                return true;
            }
        };

        struct GenericServiceId : public PlayFabBaseModel
        {
            AZStd::string ServiceName;
            AZStd::string UserId;

            GenericServiceId() :
                PlayFabBaseModel(),
                ServiceName(),
                UserId()
            {}

            GenericServiceId(const GenericServiceId& src) :
                PlayFabBaseModel(),
                ServiceName(src.ServiceName),
                UserId(src.UserId)
            {}

            GenericServiceId(const rapidjson::Value& obj) : GenericServiceId()
            {
                readFromValue(obj);
            }

            ~GenericServiceId()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ServiceName");
                writer.String(ServiceName.c_str());
                writer.String("UserId");
                writer.String(UserId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ServiceName_member = obj.FindMember("ServiceName");
                if (ServiceName_member != obj.MemberEnd() && !ServiceName_member->value.IsNull()) ServiceName = ServiceName_member->value.GetString();
                const Value::ConstMemberIterator UserId_member = obj.FindMember("UserId");
                if (UserId_member != obj.MemberEnd() && !UserId_member->value.IsNull()) UserId = UserId_member->value.GetString();

                return true;
            }
        };

        struct AddGenericIDRequest : public PlayFabBaseModel
        {
            GenericServiceId GenericId;

            AddGenericIDRequest() :
                PlayFabBaseModel(),
                GenericId()
            {}

            AddGenericIDRequest(const AddGenericIDRequest& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId)
            {}

            AddGenericIDRequest(const rapidjson::Value& obj) : AddGenericIDRequest()
            {
                readFromValue(obj);
            }

            ~AddGenericIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GenericId");
                GenericId.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericId_member = obj.FindMember("GenericId");
                if (GenericId_member != obj.MemberEnd() && !GenericId_member->value.IsNull()) GenericId = GenericServiceId(GenericId_member->value);

                return true;
            }
        };

        struct AddGenericIDResult : public PlayFabBaseModel
        {

            AddGenericIDResult() :
                PlayFabBaseModel()
            {}

            AddGenericIDResult(const AddGenericIDResult& src) :
                PlayFabBaseModel()
            {}

            AddGenericIDResult(const rapidjson::Value& obj) : AddGenericIDResult()
            {
                readFromValue(obj);
            }

            ~AddGenericIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AddOrUpdateContactEmailRequest : public PlayFabBaseModel
        {
            AZStd::string EmailAddress;

            AddOrUpdateContactEmailRequest() :
                PlayFabBaseModel(),
                EmailAddress()
            {}

            AddOrUpdateContactEmailRequest(const AddOrUpdateContactEmailRequest& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress)
            {}

            AddOrUpdateContactEmailRequest(const rapidjson::Value& obj) : AddOrUpdateContactEmailRequest()
            {
                readFromValue(obj);
            }

            ~AddOrUpdateContactEmailRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("EmailAddress");
                writer.String(EmailAddress.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EmailAddress_member = obj.FindMember("EmailAddress");
                if (EmailAddress_member != obj.MemberEnd() && !EmailAddress_member->value.IsNull()) EmailAddress = EmailAddress_member->value.GetString();

                return true;
            }
        };

        struct AddOrUpdateContactEmailResult : public PlayFabBaseModel
        {

            AddOrUpdateContactEmailResult() :
                PlayFabBaseModel()
            {}

            AddOrUpdateContactEmailResult(const AddOrUpdateContactEmailResult& src) :
                PlayFabBaseModel()
            {}

            AddOrUpdateContactEmailResult(const rapidjson::Value& obj) : AddOrUpdateContactEmailResult()
            {
                readFromValue(obj);
            }

            ~AddOrUpdateContactEmailResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AddSharedGroupMembersRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> PlayFabIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string SharedGroupId;

            AddSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                SharedGroupId()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
            {}

            AddSharedGroupMembersRequest(const rapidjson::Value& obj) : AddSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("PlayFabIds");
                writer.StartArray();
                for (auto iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
                if (PlayFabIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayFabIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayFabIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct AddSharedGroupMembersResult : public PlayFabBaseModel
        {

            AddSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const AddSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const rapidjson::Value& obj) : AddSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AddUsernamePasswordRequest : public PlayFabBaseModel
        {
            AZStd::string Email;
            AZStd::string Password;
            AZStd::string Username;

            AddUsernamePasswordRequest() :
                PlayFabBaseModel(),
                Email(),
                Password(),
                Username()
            {}

            AddUsernamePasswordRequest(const AddUsernamePasswordRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Password(src.Password),
                Username(src.Username)
            {}

            AddUsernamePasswordRequest(const rapidjson::Value& obj) : AddUsernamePasswordRequest()
            {
                readFromValue(obj);
            }

            ~AddUsernamePasswordRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Email");
                writer.String(Email.c_str());
                writer.String("Password");
                writer.String(Password.c_str());
                writer.String("Username");
                writer.String(Username.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct AddUsernamePasswordResult : public PlayFabBaseModel
        {
            AZStd::string Username;

            AddUsernamePasswordResult() :
                PlayFabBaseModel(),
                Username()
            {}

            AddUsernamePasswordResult(const AddUsernamePasswordResult& src) :
                PlayFabBaseModel(),
                Username(src.Username)
            {}

            AddUsernamePasswordResult(const rapidjson::Value& obj) : AddUsernamePasswordResult()
            {
                readFromValue(obj);
            }

            ~AddUsernamePasswordResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            AZStd::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Amount");
                writer.Int(Amount);
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

                return true;
            }
        };

        struct AndroidDevicePushNotificationRegistrationRequest : public PlayFabBaseModel
        {
            AZStd::string ConfirmationMessage;
            AZStd::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;

            AndroidDevicePushNotificationRegistrationRequest() :
                PlayFabBaseModel(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            AndroidDevicePushNotificationRegistrationRequest(const AndroidDevicePushNotificationRegistrationRequest& src) :
                PlayFabBaseModel(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
            {}

            AndroidDevicePushNotificationRegistrationRequest(const rapidjson::Value& obj) : AndroidDevicePushNotificationRegistrationRequest()
            {
                readFromValue(obj);
            }

            ~AndroidDevicePushNotificationRegistrationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ConfirmationMessage.length() > 0) {
                    writer.String("ConfirmationMessage");
                    writer.String(ConfirmationMessage.c_str());
                }
                writer.String("DeviceToken");
                writer.String(DeviceToken.c_str());
                if (SendPushNotificationConfirmation.notNull()) {
                    writer.String("SendPushNotificationConfirmation");
                    writer.Bool(SendPushNotificationConfirmation);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ConfirmationMessage_member = obj.FindMember("ConfirmationMessage");
                if (ConfirmationMessage_member != obj.MemberEnd() && !ConfirmationMessage_member->value.IsNull()) ConfirmationMessage = ConfirmationMessage_member->value.GetString();
                const Value::ConstMemberIterator DeviceToken_member = obj.FindMember("DeviceToken");
                if (DeviceToken_member != obj.MemberEnd() && !DeviceToken_member->value.IsNull()) DeviceToken = DeviceToken_member->value.GetString();
                const Value::ConstMemberIterator SendPushNotificationConfirmation_member = obj.FindMember("SendPushNotificationConfirmation");
                if (SendPushNotificationConfirmation_member != obj.MemberEnd() && !SendPushNotificationConfirmation_member->value.IsNull()) SendPushNotificationConfirmation = SendPushNotificationConfirmation_member->value.GetBool();

                return true;
            }
        };

        struct AndroidDevicePushNotificationRegistrationResult : public PlayFabBaseModel
        {

            AndroidDevicePushNotificationRegistrationResult() :
                PlayFabBaseModel()
            {}

            AndroidDevicePushNotificationRegistrationResult(const AndroidDevicePushNotificationRegistrationResult& src) :
                PlayFabBaseModel()
            {}

            AndroidDevicePushNotificationRegistrationResult(const rapidjson::Value& obj) : AndroidDevicePushNotificationRegistrationResult()
            {
                readFromValue(obj);
            }

            ~AndroidDevicePushNotificationRegistrationResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AttributeInstallRequest : public PlayFabBaseModel
        {
            AZStd::string Adid;
            AZStd::string Idfa;

            AttributeInstallRequest() :
                PlayFabBaseModel(),
                Adid(),
                Idfa()
            {}

            AttributeInstallRequest(const AttributeInstallRequest& src) :
                PlayFabBaseModel(),
                Adid(src.Adid),
                Idfa(src.Idfa)
            {}

            AttributeInstallRequest(const rapidjson::Value& obj) : AttributeInstallRequest()
            {
                readFromValue(obj);
            }

            ~AttributeInstallRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Adid.length() > 0) {
                    writer.String("Adid");
                    writer.String(Adid.c_str());
                }
                if (Idfa.length() > 0) {
                    writer.String("Idfa");
                    writer.String(Idfa.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Adid_member = obj.FindMember("Adid");
                if (Adid_member != obj.MemberEnd() && !Adid_member->value.IsNull()) Adid = Adid_member->value.GetString();
                const Value::ConstMemberIterator Idfa_member = obj.FindMember("Idfa");
                if (Idfa_member != obj.MemberEnd() && !Idfa_member->value.IsNull()) Idfa = Idfa_member->value.GetString();

                return true;
            }
        };

        struct AttributeInstallResult : public PlayFabBaseModel
        {

            AttributeInstallResult() :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const AttributeInstallResult& src) :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const rapidjson::Value& obj) : AttributeInstallResult()
            {
                readFromValue(obj);
            }

            ~AttributeInstallResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct CancelTradeRequest : public PlayFabBaseModel
        {
            AZStd::string TradeId;

            CancelTradeRequest() :
                PlayFabBaseModel(),
                TradeId()
            {}

            CancelTradeRequest(const CancelTradeRequest& src) :
                PlayFabBaseModel(),
                TradeId(src.TradeId)
            {}

            CancelTradeRequest(const rapidjson::Value& obj) : CancelTradeRequest()
            {
                readFromValue(obj);
            }

            ~CancelTradeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("TradeId");
                writer.String(TradeId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

                return true;
            }
        };

        struct CancelTradeResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            CancelTradeResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            CancelTradeResponse(const CancelTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            CancelTradeResponse(const rapidjson::Value& obj) : CancelTradeResponse()
            {
                readFromValue(obj);
            }

            ~CancelTradeResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct CartItem : public PlayFabBaseModel
        {
            AZStd::string Description;
            AZStd::string DisplayName;
            AZStd::string ItemClass;
            AZStd::string ItemId;
            AZStd::string ItemInstanceId;
            std::map<AZStd::string, Uint32> RealCurrencyPrices;
            std::map<AZStd::string, Uint32> VCAmount;
            std::map<AZStd::string, Uint32> VirtualCurrencyPrices;

            CartItem() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                RealCurrencyPrices(),
                VCAmount(),
                VirtualCurrencyPrices()
            {}

            CartItem(const CartItem& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VCAmount(src.VCAmount),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            CartItem(const rapidjson::Value& obj) : CartItem()
            {
                readFromValue(obj);
            }

            ~CartItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (ItemClass.length() > 0) {
                    writer.String("ItemClass");
                    writer.String(ItemClass.c_str());
                }
                if (ItemId.length() > 0) {
                    writer.String("ItemId");
                    writer.String(ItemId.c_str());
                }
                if (ItemInstanceId.length() > 0) {
                    writer.String("ItemInstanceId");
                    writer.String(ItemInstanceId.c_str());
                }
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VCAmount.empty()) {
                    writer.String("VCAmount");
                    writer.StartObject();
                    for (auto iter = VCAmount.begin(); iter != VCAmount.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyPrices.empty()) {
                    writer.String("VirtualCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
                if (RealCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator VCAmount_member = obj.FindMember("VCAmount");
                if (VCAmount_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VCAmount_member->value.MemberBegin(); iter != VCAmount_member->value.MemberEnd(); ++iter) {
                        VCAmount[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
                if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct CatalogItemBundleInfo : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> BundledItems; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> BundledResultTables; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, Uint32> BundledVirtualCurrencies;

            CatalogItemBundleInfo() :
                PlayFabBaseModel(),
                BundledItems(),
                BundledResultTables(),
                BundledVirtualCurrencies()
            {}

            CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
                PlayFabBaseModel(),
                BundledItems(src.BundledItems),
                BundledResultTables(src.BundledResultTables),
                BundledVirtualCurrencies(src.BundledVirtualCurrencies)
            {}

            CatalogItemBundleInfo(const rapidjson::Value& obj) : CatalogItemBundleInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemBundleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!BundledItems.empty()) {
                    writer.String("BundledItems");
                    writer.StartArray();
                    for (auto iter = BundledItems.begin(); iter != BundledItems.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!BundledResultTables.empty()) {
                    writer.String("BundledResultTables");
                    writer.StartArray();
                    for (auto iter = BundledResultTables.begin(); iter != BundledResultTables.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!BundledVirtualCurrencies.empty()) {
                    writer.String("BundledVirtualCurrencies");
                    writer.StartObject();
                    for (auto iter = BundledVirtualCurrencies.begin(); iter != BundledVirtualCurrencies.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BundledItems_member = obj.FindMember("BundledItems");
                if (BundledItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BundledItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BundledItems.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator BundledResultTables_member = obj.FindMember("BundledResultTables");
                if (BundledResultTables_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BundledResultTables_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BundledResultTables.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator BundledVirtualCurrencies_member = obj.FindMember("BundledVirtualCurrencies");
                if (BundledVirtualCurrencies_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = BundledVirtualCurrencies_member->value.MemberBegin(); iter != BundledVirtualCurrencies_member->value.MemberEnd(); ++iter) {
                        BundledVirtualCurrencies[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
            OptionalUint32 UsageCount;
            OptionalUint32 UsagePeriod;
            AZStd::string UsagePeriodGroup;

            CatalogItemConsumableInfo() :
                PlayFabBaseModel(),
                UsageCount(),
                UsagePeriod(),
                UsagePeriodGroup()
            {}

            CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
                PlayFabBaseModel(),
                UsageCount(src.UsageCount),
                UsagePeriod(src.UsagePeriod),
                UsagePeriodGroup(src.UsagePeriodGroup)
            {}

            CatalogItemConsumableInfo(const rapidjson::Value& obj) : CatalogItemConsumableInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemConsumableInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (UsageCount.notNull()) {
                    writer.String("UsageCount");
                    writer.Uint(UsageCount);
                }
                if (UsagePeriod.notNull()) {
                    writer.String("UsagePeriod");
                    writer.Uint(UsagePeriod);
                }
                if (UsagePeriodGroup.length() > 0) {
                    writer.String("UsagePeriodGroup");
                    writer.String(UsagePeriodGroup.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UsageCount_member = obj.FindMember("UsageCount");
                if (UsageCount_member != obj.MemberEnd() && !UsageCount_member->value.IsNull()) UsageCount = UsageCount_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriod_member = obj.FindMember("UsagePeriod");
                if (UsagePeriod_member != obj.MemberEnd() && !UsagePeriod_member->value.IsNull()) UsagePeriod = UsagePeriod_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriodGroup_member = obj.FindMember("UsagePeriodGroup");
                if (UsagePeriodGroup_member != obj.MemberEnd() && !UsagePeriodGroup_member->value.IsNull()) UsagePeriodGroup = UsagePeriodGroup_member->value.GetString();

                return true;
            }
        };

        struct CatalogItemContainerInfo : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> ItemContents; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string KeyItemId;
            AZStd::vector<AZStd::string> ResultTableContents; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                ItemContents(),
                KeyItemId(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                ItemContents(src.ItemContents),
                KeyItemId(src.KeyItemId),
                ResultTableContents(src.ResultTableContents),
                VirtualCurrencyContents(src.VirtualCurrencyContents)
            {}

            CatalogItemContainerInfo(const rapidjson::Value& obj) : CatalogItemContainerInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemContainerInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!ItemContents.empty()) {
                    writer.String("ItemContents");
                    writer.StartArray();
                    for (auto iter = ItemContents.begin(); iter != ItemContents.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (KeyItemId.length() > 0) {
                    writer.String("KeyItemId");
                    writer.String(KeyItemId.c_str());
                }
                if (!ResultTableContents.empty()) {
                    writer.String("ResultTableContents");
                    writer.StartArray();
                    for (auto iter = ResultTableContents.begin(); iter != ResultTableContents.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrencyContents.empty()) {
                    writer.String("VirtualCurrencyContents");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyContents.begin(); iter != VirtualCurrencyContents.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemContents_member = obj.FindMember("ItemContents");
                if (ItemContents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ItemContents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ItemContents.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator KeyItemId_member = obj.FindMember("KeyItemId");
                if (KeyItemId_member != obj.MemberEnd() && !KeyItemId_member->value.IsNull()) KeyItemId = KeyItemId_member->value.GetString();
                const Value::ConstMemberIterator ResultTableContents_member = obj.FindMember("ResultTableContents");
                if (ResultTableContents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ResultTableContents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ResultTableContents.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyContents_member = obj.FindMember("VirtualCurrencyContents");
                if (VirtualCurrencyContents_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyContents_member->value.MemberBegin(); iter != VirtualCurrencyContents_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyContents[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct CatalogItem : public PlayFabBaseModel
        {
            CatalogItemBundleInfo* Bundle;
            bool CanBecomeCharacter;
            AZStd::string CatalogVersion;
            CatalogItemConsumableInfo* Consumable;
            CatalogItemContainerInfo* Container;
            AZStd::string CustomData;
            AZStd::string Description;
            AZStd::string DisplayName;
            Int32 InitialLimitedEditionCount;
            bool IsLimitedEdition;
            bool IsStackable;
            bool IsTradable;
            AZStd::string ItemClass;
            AZStd::string ItemId;
            AZStd::string ItemImageUrl;
            std::map<AZStd::string, Uint32> RealCurrencyPrices;
            AZStd::vector<AZStd::string> Tags; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, Uint32> VirtualCurrencyPrices;

            CatalogItem() :
                PlayFabBaseModel(),
                Bundle(nullptr),
                CanBecomeCharacter(false),
                CatalogVersion(),
                Consumable(nullptr),
                Container(nullptr),
                CustomData(),
                Description(),
                DisplayName(),
                InitialLimitedEditionCount(0),
                IsLimitedEdition(false),
                IsStackable(false),
                IsTradable(false),
                ItemClass(),
                ItemId(),
                ItemImageUrl(),
                RealCurrencyPrices(),
                Tags(),
                VirtualCurrencyPrices()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : nullptr),
                CanBecomeCharacter(src.CanBecomeCharacter),
                CatalogVersion(src.CatalogVersion),
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : nullptr),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : nullptr),
                CustomData(src.CustomData),
                Description(src.Description),
                DisplayName(src.DisplayName),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount),
                IsLimitedEdition(src.IsLimitedEdition),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemImageUrl(src.ItemImageUrl),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem()
            {
                if (Bundle != nullptr) delete Bundle;
                if (Consumable != nullptr) delete Consumable;
                if (Container != nullptr) delete Container;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Bundle != nullptr) {
                    writer.String("Bundle");
                    Bundle->writeJSON(writer);
                }
                writer.String("CanBecomeCharacter");
                writer.Bool(CanBecomeCharacter);
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (Consumable != nullptr) {
                    writer.String("Consumable");
                    Consumable->writeJSON(writer);
                }
                if (Container != nullptr) {
                    writer.String("Container");
                    Container->writeJSON(writer);
                }
                if (CustomData.length() > 0) {
                    writer.String("CustomData");
                    writer.String(CustomData.c_str());
                }
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                writer.String("InitialLimitedEditionCount");
                writer.Int(InitialLimitedEditionCount);
                writer.String("IsLimitedEdition");
                writer.Bool(IsLimitedEdition);
                writer.String("IsStackable");
                writer.Bool(IsStackable);
                writer.String("IsTradable");
                writer.Bool(IsTradable);
                if (ItemClass.length() > 0) {
                    writer.String("ItemClass");
                    writer.String(ItemClass.c_str());
                }
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                if (ItemImageUrl.length() > 0) {
                    writer.String("ItemImageUrl");
                    writer.String(ItemImageUrl.c_str());
                }
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (auto iter = Tags.begin(); iter != Tags.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrencyPrices.empty()) {
                    writer.String("VirtualCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Bundle_member = obj.FindMember("Bundle");
                if (Bundle_member != obj.MemberEnd() && !Bundle_member->value.IsNull()) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
                const Value::ConstMemberIterator CanBecomeCharacter_member = obj.FindMember("CanBecomeCharacter");
                if (CanBecomeCharacter_member != obj.MemberEnd() && !CanBecomeCharacter_member->value.IsNull()) CanBecomeCharacter = CanBecomeCharacter_member->value.GetBool();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator Consumable_member = obj.FindMember("Consumable");
                if (Consumable_member != obj.MemberEnd() && !Consumable_member->value.IsNull()) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
                const Value::ConstMemberIterator Container_member = obj.FindMember("Container");
                if (Container_member != obj.MemberEnd() && !Container_member->value.IsNull()) Container = new CatalogItemContainerInfo(Container_member->value);
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator InitialLimitedEditionCount_member = obj.FindMember("InitialLimitedEditionCount");
                if (InitialLimitedEditionCount_member != obj.MemberEnd() && !InitialLimitedEditionCount_member->value.IsNull()) InitialLimitedEditionCount = InitialLimitedEditionCount_member->value.GetInt();
                const Value::ConstMemberIterator IsLimitedEdition_member = obj.FindMember("IsLimitedEdition");
                if (IsLimitedEdition_member != obj.MemberEnd() && !IsLimitedEdition_member->value.IsNull()) IsLimitedEdition = IsLimitedEdition_member->value.GetBool();
                const Value::ConstMemberIterator IsStackable_member = obj.FindMember("IsStackable");
                if (IsStackable_member != obj.MemberEnd() && !IsStackable_member->value.IsNull()) IsStackable = IsStackable_member->value.GetBool();
                const Value::ConstMemberIterator IsTradable_member = obj.FindMember("IsTradable");
                if (IsTradable_member != obj.MemberEnd() && !IsTradable_member->value.IsNull()) IsTradable = IsTradable_member->value.GetBool();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemImageUrl_member = obj.FindMember("ItemImageUrl");
                if (ItemImageUrl_member != obj.MemberEnd() && !ItemImageUrl_member->value.IsNull()) ItemImageUrl = ItemImageUrl_member->value.GetString();
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
                if (RealCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
                if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            AZStd::string Annotation;
            AZStd::vector<AZStd::string> BundleContents; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string BundleParent;
            AZStd::string CatalogVersion;
            std::map<AZStd::string, AZStd::string> CustomData;
            AZStd::string DisplayName;
            OptionalTime Expiration;
            AZStd::string ItemClass;
            AZStd::string ItemId;
            AZStd::string ItemInstanceId;
            OptionalTime PurchaseDate;
            OptionalInt32 RemainingUses;
            AZStd::string UnitCurrency;
            Uint32 UnitPrice;
            OptionalInt32 UsesIncrementedBy;

            ItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PurchaseDate(),
                RemainingUses(),
                UnitCurrency(),
                UnitPrice(0),
                UsesIncrementedBy()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            ItemInstance(const rapidjson::Value& obj) : ItemInstance()
            {
                readFromValue(obj);
            }

            ~ItemInstance()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Annotation.length() > 0) {
                    writer.String("Annotation");
                    writer.String(Annotation.c_str());
                }
                if (!BundleContents.empty()) {
                    writer.String("BundleContents");
                    writer.StartArray();
                    for (auto iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (BundleParent.length() > 0) {
                    writer.String("BundleParent");
                    writer.String(BundleParent.c_str());
                }
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (!CustomData.empty()) {
                    writer.String("CustomData");
                    writer.StartObject();
                    for (auto iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (Expiration.notNull()) {
                    writer.String("Expiration");
                    writeDatetime(Expiration, writer);
                }
                if (ItemClass.length() > 0) {
                    writer.String("ItemClass");
                    writer.String(ItemClass.c_str());
                }
                if (ItemId.length() > 0) {
                    writer.String("ItemId");
                    writer.String(ItemId.c_str());
                }
                if (ItemInstanceId.length() > 0) {
                    writer.String("ItemInstanceId");
                    writer.String(ItemInstanceId.c_str());
                }
                if (PurchaseDate.notNull()) {
                    writer.String("PurchaseDate");
                    writeDatetime(PurchaseDate, writer);
                }
                if (RemainingUses.notNull()) {
                    writer.String("RemainingUses");
                    writer.Int(RemainingUses);
                }
                if (UnitCurrency.length() > 0) {
                    writer.String("UnitCurrency");
                    writer.String(UnitCurrency.c_str());
                }
                writer.String("UnitPrice");
                writer.Uint(UnitPrice);
                if (UsesIncrementedBy.notNull()) {
                    writer.String("UsesIncrementedBy");
                    writer.Int(UsesIncrementedBy);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
                if (BundleContents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BundleContents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BundleContents.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
                if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
                        CustomData[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
                if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
                const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
                if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
                const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
                if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
                const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
                if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();

                return true;
            }
        };

        struct CharacterInventory : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            AZStd::vector<ItemInstance> Inventory; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            CharacterInventory() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory()
            {}

            CharacterInventory(const CharacterInventory& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory)
            {}

            CharacterInventory(const rapidjson::Value& obj) : CharacterInventory()
            {
                readFromValue(obj);
            }

            ~CharacterInventory()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (!Inventory.empty()) {
                    writer.String("Inventory");
                    writer.StartArray();
                    for (auto iter = Inventory.begin(); iter != Inventory.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
                if (Inventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Inventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Inventory.push_back(ItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            AZStd::string CharacterName;
            AZStd::string CharacterType;
            AZStd::string DisplayName;
            AZStd::string PlayFabId;
            Int32 Position;
            Int32 StatValue;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType(),
                DisplayName(),
                PlayFabId(),
                Position(0),
                StatValue(0)
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                StatValue(src.StatValue)
            {}

            CharacterLeaderboardEntry(const rapidjson::Value& obj) : CharacterLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~CharacterLeaderboardEntry()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CharacterName.length() > 0) {
                    writer.String("CharacterName");
                    writer.String(CharacterName.c_str());
                }
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("Position");
                writer.Int(Position);
                writer.String("StatValue");
                writer.Int(StatValue);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
                if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();
                const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
                if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();

                return true;
            }
        };

        struct CharacterResult : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            AZStd::string CharacterName;
            AZStd::string CharacterType;

            CharacterResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType()
            {}

            CharacterResult(const CharacterResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType)
            {}

            CharacterResult(const rapidjson::Value& obj) : CharacterResult()
            {
                readFromValue(obj);
            }

            ~CharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CharacterName.length() > 0) {
                    writer.String("CharacterName");
                    writer.String(CharacterName.c_str());
                }
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

                return true;
            }
        };

        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CloudScriptRevisionOptionLive: writer.String("Live"); break;
            case CloudScriptRevisionOptionLatest: writer.String("Latest"); break;
            case CloudScriptRevisionOptionSpecific: writer.String("Specific"); break;

            }
        }

        inline CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<CloudScriptRevisionOption>(obj.GetInt());

            static std::map<const char *, CloudScriptRevisionOption, PlayFabClientSdk::StringCompare> _CloudScriptRevisionOptionMap;
            if (_CloudScriptRevisionOptionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CloudScriptRevisionOptionMap["Live"] = CloudScriptRevisionOptionLive;
                _CloudScriptRevisionOptionMap["Latest"] = CloudScriptRevisionOptionLatest;
                _CloudScriptRevisionOptionMap["Specific"] = CloudScriptRevisionOptionSpecific;

            }

            auto output = _CloudScriptRevisionOptionMap.find(obj.GetString());
            if (output != _CloudScriptRevisionOptionMap.end())
                return output->second;

            return CloudScriptRevisionOptionLive; // Basically critical fail
        }

        struct Container_Dictionary_String_String : public PlayFabBaseModel
        {
            std::map<AZStd::string, AZStd::string> Data;

            Container_Dictionary_String_String() :
                PlayFabBaseModel(),
                Data()
            {}

            Container_Dictionary_String_String(const Container_Dictionary_String_String& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            Container_Dictionary_String_String(const rapidjson::Value& obj) : Container_Dictionary_String_String()
            {
                readFromValue(obj);
            }

            ~Container_Dictionary_String_String()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct CollectionFilter : public PlayFabBaseModel
        {
            AZStd::vector<Container_Dictionary_String_String> Excludes; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<Container_Dictionary_String_String> Includes; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            CollectionFilter() :
                PlayFabBaseModel(),
                Excludes(),
                Includes()
            {}

            CollectionFilter(const CollectionFilter& src) :
                PlayFabBaseModel(),
                Excludes(src.Excludes),
                Includes(src.Includes)
            {}

            CollectionFilter(const rapidjson::Value& obj) : CollectionFilter()
            {
                readFromValue(obj);
            }

            ~CollectionFilter()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Excludes.empty()) {
                    writer.String("Excludes");
                    writer.StartArray();
                    for (auto iter = Excludes.begin(); iter != Excludes.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Includes.empty()) {
                    writer.String("Includes");
                    writer.StartArray();
                    for (auto iter = Includes.begin(); iter != Includes.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Excludes_member = obj.FindMember("Excludes");
                if (Excludes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Excludes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Excludes.push_back(Container_Dictionary_String_String(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Includes_member = obj.FindMember("Includes");
                if (Includes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Includes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Includes.push_back(Container_Dictionary_String_String(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ConfirmPurchaseRequest : public PlayFabBaseModel
        {
            AZStd::string OrderId;

            ConfirmPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId()
            {}

            ConfirmPurchaseRequest(const ConfirmPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId)
            {}

            ConfirmPurchaseRequest(const rapidjson::Value& obj) : ConfirmPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ConfirmPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();

                return true;
            }
        };

        struct ConfirmPurchaseResult : public PlayFabBaseModel
        {
            AZStd::vector<ItemInstance> Items; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string OrderId;
            time_t PurchaseDate;

            ConfirmPurchaseResult() :
                PlayFabBaseModel(),
                Items(),
                OrderId(),
                PurchaseDate(0)
            {}

            ConfirmPurchaseResult(const ConfirmPurchaseResult& src) :
                PlayFabBaseModel(),
                Items(src.Items),
                OrderId(src.OrderId),
                PurchaseDate(src.PurchaseDate)
            {}

            ConfirmPurchaseResult(const rapidjson::Value& obj) : ConfirmPurchaseResult()
            {
                readFromValue(obj);
            }

            ~ConfirmPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Items.empty()) {
                    writer.String("Items");
                    writer.StartArray();
                    for (auto iter = Items.begin(); iter != Items.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                writer.String("PurchaseDate");
                writeDatetime(PurchaseDate, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Items_member = obj.FindMember("Items");
                if (Items_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Items_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Items.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);

                return true;
            }
        };

        struct ConsumeItemRequest : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            Int32 ConsumeCount;
            AZStd::string ItemInstanceId;

            ConsumeItemRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ConsumeCount(0),
                ItemInstanceId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ConsumeCount(src.ConsumeCount),
                ItemInstanceId(src.ItemInstanceId)
            {}

            ConsumeItemRequest(const rapidjson::Value& obj) : ConsumeItemRequest()
            {
                readFromValue(obj);
            }

            ~ConsumeItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.String("ConsumeCount");
                writer.Int(ConsumeCount);
                writer.String("ItemInstanceId");
                writer.String(ItemInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ConsumeCount_member = obj.FindMember("ConsumeCount");
                if (ConsumeCount_member != obj.MemberEnd() && !ConsumeCount_member->value.IsNull()) ConsumeCount = ConsumeCount_member->value.GetInt();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct ConsumeItemResult : public PlayFabBaseModel
        {
            AZStd::string ItemInstanceId;
            Int32 RemainingUses;

            ConsumeItemResult() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                RemainingUses(0)
            {}

            ConsumeItemResult(const ConsumeItemResult& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ConsumeItemResult(const rapidjson::Value& obj) : ConsumeItemResult()
            {
                readFromValue(obj);
            }

            ~ConsumeItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ItemInstanceId.length() > 0) {
                    writer.String("ItemInstanceId");
                    writer.String(ItemInstanceId.c_str());
                }
                writer.String("RemainingUses");
                writer.Int(RemainingUses);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

                return true;
            }
        };

        enum EmailVerificationStatus
        {
            EmailVerificationStatusUnverified,
            EmailVerificationStatusPending,
            EmailVerificationStatusConfirmed
        };

        inline void writeEmailVerificationStatusEnumJSON(EmailVerificationStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EmailVerificationStatusUnverified: writer.String("Unverified"); break;
            case EmailVerificationStatusPending: writer.String("Pending"); break;
            case EmailVerificationStatusConfirmed: writer.String("Confirmed"); break;

            }
        }

        inline EmailVerificationStatus readEmailVerificationStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EmailVerificationStatus>(obj.GetInt());

            static std::map<const char *, EmailVerificationStatus, PlayFabClientSdk::StringCompare> _EmailVerificationStatusMap;
            if (_EmailVerificationStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EmailVerificationStatusMap["Unverified"] = EmailVerificationStatusUnverified;
                _EmailVerificationStatusMap["Pending"] = EmailVerificationStatusPending;
                _EmailVerificationStatusMap["Confirmed"] = EmailVerificationStatusConfirmed;

            }

            auto output = _EmailVerificationStatusMap.find(obj.GetString());
            if (output != _EmailVerificationStatusMap.end())
                return output->second;

            return EmailVerificationStatusUnverified; // Basically critical fail
        }

        struct ContactEmailInfoModel : public PlayFabBaseModel
        {
            AZStd::string EmailAddress;
            AZStd::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfoModel() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfoModel(const ContactEmailInfoModel& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ContactEmailInfoModel(const rapidjson::Value& obj) : ContactEmailInfoModel()
            {
                readFromValue(obj);
            }

            ~ContactEmailInfoModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (EmailAddress.length() > 0) {
                    writer.String("EmailAddress");
                    writer.String(EmailAddress.c_str());
                }
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                if (VerificationStatus.notNull()) {
                    writer.String("VerificationStatus");
                    writeEmailVerificationStatusEnumJSON(VerificationStatus, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EmailAddress_member = obj.FindMember("EmailAddress");
                if (EmailAddress_member != obj.MemberEnd() && !EmailAddress_member->value.IsNull()) EmailAddress = EmailAddress_member->value.GetString();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator VerificationStatus_member = obj.FindMember("VerificationStatus");
                if (VerificationStatus_member != obj.MemberEnd() && !VerificationStatus_member->value.IsNull()) VerificationStatus = readEmailVerificationStatusFromValue(VerificationStatus_member->value);

                return true;
            }
        };

        enum ContinentCode
        {
            ContinentCodeAF,
            ContinentCodeAN,
            ContinentCodeAS,
            ContinentCodeEU,
            ContinentCodeNA,
            ContinentCodeOC,
            ContinentCodeSA
        };

        inline void writeContinentCodeEnumJSON(ContinentCode enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ContinentCodeAF: writer.String("AF"); break;
            case ContinentCodeAN: writer.String("AN"); break;
            case ContinentCodeAS: writer.String("AS"); break;
            case ContinentCodeEU: writer.String("EU"); break;
            case ContinentCodeNA: writer.String("NA"); break;
            case ContinentCodeOC: writer.String("OC"); break;
            case ContinentCodeSA: writer.String("SA"); break;

            }
        }

        inline ContinentCode readContinentCodeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<ContinentCode>(obj.GetInt());

            static std::map<const char *, ContinentCode, PlayFabClientSdk::StringCompare> _ContinentCodeMap;
            if (_ContinentCodeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ContinentCodeMap["AF"] = ContinentCodeAF;
                _ContinentCodeMap["AN"] = ContinentCodeAN;
                _ContinentCodeMap["AS"] = ContinentCodeAS;
                _ContinentCodeMap["EU"] = ContinentCodeEU;
                _ContinentCodeMap["NA"] = ContinentCodeNA;
                _ContinentCodeMap["OC"] = ContinentCodeOC;
                _ContinentCodeMap["SA"] = ContinentCodeSA;

            }

            auto output = _ContinentCodeMap.find(obj.GetString());
            if (output != _ContinentCodeMap.end())
                return output->second;

            return ContinentCodeAF; // Basically critical fail
        }

        enum CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        inline void writeCountryCodeEnumJSON(CountryCode enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CountryCodeAF: writer.String("AF"); break;
            case CountryCodeAX: writer.String("AX"); break;
            case CountryCodeAL: writer.String("AL"); break;
            case CountryCodeDZ: writer.String("DZ"); break;
            case CountryCodeAS: writer.String("AS"); break;
            case CountryCodeAD: writer.String("AD"); break;
            case CountryCodeAO: writer.String("AO"); break;
            case CountryCodeAI: writer.String("AI"); break;
            case CountryCodeAQ: writer.String("AQ"); break;
            case CountryCodeAG: writer.String("AG"); break;
            case CountryCodeAR: writer.String("AR"); break;
            case CountryCodeAM: writer.String("AM"); break;
            case CountryCodeAW: writer.String("AW"); break;
            case CountryCodeAU: writer.String("AU"); break;
            case CountryCodeAT: writer.String("AT"); break;
            case CountryCodeAZ: writer.String("AZ"); break;
            case CountryCodeBS: writer.String("BS"); break;
            case CountryCodeBH: writer.String("BH"); break;
            case CountryCodeBD: writer.String("BD"); break;
            case CountryCodeBB: writer.String("BB"); break;
            case CountryCodeBY: writer.String("BY"); break;
            case CountryCodeBE: writer.String("BE"); break;
            case CountryCodeBZ: writer.String("BZ"); break;
            case CountryCodeBJ: writer.String("BJ"); break;
            case CountryCodeBM: writer.String("BM"); break;
            case CountryCodeBT: writer.String("BT"); break;
            case CountryCodeBO: writer.String("BO"); break;
            case CountryCodeBQ: writer.String("BQ"); break;
            case CountryCodeBA: writer.String("BA"); break;
            case CountryCodeBW: writer.String("BW"); break;
            case CountryCodeBV: writer.String("BV"); break;
            case CountryCodeBR: writer.String("BR"); break;
            case CountryCodeIO: writer.String("IO"); break;
            case CountryCodeBN: writer.String("BN"); break;
            case CountryCodeBG: writer.String("BG"); break;
            case CountryCodeBF: writer.String("BF"); break;
            case CountryCodeBI: writer.String("BI"); break;
            case CountryCodeKH: writer.String("KH"); break;
            case CountryCodeCM: writer.String("CM"); break;
            case CountryCodeCA: writer.String("CA"); break;
            case CountryCodeCV: writer.String("CV"); break;
            case CountryCodeKY: writer.String("KY"); break;
            case CountryCodeCF: writer.String("CF"); break;
            case CountryCodeTD: writer.String("TD"); break;
            case CountryCodeCL: writer.String("CL"); break;
            case CountryCodeCN: writer.String("CN"); break;
            case CountryCodeCX: writer.String("CX"); break;
            case CountryCodeCC: writer.String("CC"); break;
            case CountryCodeCO: writer.String("CO"); break;
            case CountryCodeKM: writer.String("KM"); break;
            case CountryCodeCG: writer.String("CG"); break;
            case CountryCodeCD: writer.String("CD"); break;
            case CountryCodeCK: writer.String("CK"); break;
            case CountryCodeCR: writer.String("CR"); break;
            case CountryCodeCI: writer.String("CI"); break;
            case CountryCodeHR: writer.String("HR"); break;
            case CountryCodeCU: writer.String("CU"); break;
            case CountryCodeCW: writer.String("CW"); break;
            case CountryCodeCY: writer.String("CY"); break;
            case CountryCodeCZ: writer.String("CZ"); break;
            case CountryCodeDK: writer.String("DK"); break;
            case CountryCodeDJ: writer.String("DJ"); break;
            case CountryCodeDM: writer.String("DM"); break;
            case CountryCodeDO: writer.String("DO"); break;
            case CountryCodeEC: writer.String("EC"); break;
            case CountryCodeEG: writer.String("EG"); break;
            case CountryCodeSV: writer.String("SV"); break;
            case CountryCodeGQ: writer.String("GQ"); break;
            case CountryCodeER: writer.String("ER"); break;
            case CountryCodeEE: writer.String("EE"); break;
            case CountryCodeET: writer.String("ET"); break;
            case CountryCodeFK: writer.String("FK"); break;
            case CountryCodeFO: writer.String("FO"); break;
            case CountryCodeFJ: writer.String("FJ"); break;
            case CountryCodeFI: writer.String("FI"); break;
            case CountryCodeFR: writer.String("FR"); break;
            case CountryCodeGF: writer.String("GF"); break;
            case CountryCodePF: writer.String("PF"); break;
            case CountryCodeTF: writer.String("TF"); break;
            case CountryCodeGA: writer.String("GA"); break;
            case CountryCodeGM: writer.String("GM"); break;
            case CountryCodeGE: writer.String("GE"); break;
            case CountryCodeDE: writer.String("DE"); break;
            case CountryCodeGH: writer.String("GH"); break;
            case CountryCodeGI: writer.String("GI"); break;
            case CountryCodeGR: writer.String("GR"); break;
            case CountryCodeGL: writer.String("GL"); break;
            case CountryCodeGD: writer.String("GD"); break;
            case CountryCodeGP: writer.String("GP"); break;
            case CountryCodeGU: writer.String("GU"); break;
            case CountryCodeGT: writer.String("GT"); break;
            case CountryCodeGG: writer.String("GG"); break;
            case CountryCodeGN: writer.String("GN"); break;
            case CountryCodeGW: writer.String("GW"); break;
            case CountryCodeGY: writer.String("GY"); break;
            case CountryCodeHT: writer.String("HT"); break;
            case CountryCodeHM: writer.String("HM"); break;
            case CountryCodeVA: writer.String("VA"); break;
            case CountryCodeHN: writer.String("HN"); break;
            case CountryCodeHK: writer.String("HK"); break;
            case CountryCodeHU: writer.String("HU"); break;
            case CountryCodeIS: writer.String("IS"); break;
            case CountryCodeIN: writer.String("IN"); break;
            case CountryCodeID: writer.String("ID"); break;
            case CountryCodeIR: writer.String("IR"); break;
            case CountryCodeIQ: writer.String("IQ"); break;
            case CountryCodeIE: writer.String("IE"); break;
            case CountryCodeIM: writer.String("IM"); break;
            case CountryCodeIL: writer.String("IL"); break;
            case CountryCodeIT: writer.String("IT"); break;
            case CountryCodeJM: writer.String("JM"); break;
            case CountryCodeJP: writer.String("JP"); break;
            case CountryCodeJE: writer.String("JE"); break;
            case CountryCodeJO: writer.String("JO"); break;
            case CountryCodeKZ: writer.String("KZ"); break;
            case CountryCodeKE: writer.String("KE"); break;
            case CountryCodeKI: writer.String("KI"); break;
            case CountryCodeKP: writer.String("KP"); break;
            case CountryCodeKR: writer.String("KR"); break;
            case CountryCodeKW: writer.String("KW"); break;
            case CountryCodeKG: writer.String("KG"); break;
            case CountryCodeLA: writer.String("LA"); break;
            case CountryCodeLV: writer.String("LV"); break;
            case CountryCodeLB: writer.String("LB"); break;
            case CountryCodeLS: writer.String("LS"); break;
            case CountryCodeLR: writer.String("LR"); break;
            case CountryCodeLY: writer.String("LY"); break;
            case CountryCodeLI: writer.String("LI"); break;
            case CountryCodeLT: writer.String("LT"); break;
            case CountryCodeLU: writer.String("LU"); break;
            case CountryCodeMO: writer.String("MO"); break;
            case CountryCodeMK: writer.String("MK"); break;
            case CountryCodeMG: writer.String("MG"); break;
            case CountryCodeMW: writer.String("MW"); break;
            case CountryCodeMY: writer.String("MY"); break;
            case CountryCodeMV: writer.String("MV"); break;
            case CountryCodeML: writer.String("ML"); break;
            case CountryCodeMT: writer.String("MT"); break;
            case CountryCodeMH: writer.String("MH"); break;
            case CountryCodeMQ: writer.String("MQ"); break;
            case CountryCodeMR: writer.String("MR"); break;
            case CountryCodeMU: writer.String("MU"); break;
            case CountryCodeYT: writer.String("YT"); break;
            case CountryCodeMX: writer.String("MX"); break;
            case CountryCodeFM: writer.String("FM"); break;
            case CountryCodeMD: writer.String("MD"); break;
            case CountryCodeMC: writer.String("MC"); break;
            case CountryCodeMN: writer.String("MN"); break;
            case CountryCodeME: writer.String("ME"); break;
            case CountryCodeMS: writer.String("MS"); break;
            case CountryCodeMA: writer.String("MA"); break;
            case CountryCodeMZ: writer.String("MZ"); break;
            case CountryCodeMM: writer.String("MM"); break;
            case CountryCodeNA: writer.String("NA"); break;
            case CountryCodeNR: writer.String("NR"); break;
            case CountryCodeNP: writer.String("NP"); break;
            case CountryCodeNL: writer.String("NL"); break;
            case CountryCodeNC: writer.String("NC"); break;
            case CountryCodeNZ: writer.String("NZ"); break;
            case CountryCodeNI: writer.String("NI"); break;
            case CountryCodeNE: writer.String("NE"); break;
            case CountryCodeNG: writer.String("NG"); break;
            case CountryCodeNU: writer.String("NU"); break;
            case CountryCodeNF: writer.String("NF"); break;
            case CountryCodeMP: writer.String("MP"); break;
            case CountryCodeNO: writer.String("NO"); break;
            case CountryCodeOM: writer.String("OM"); break;
            case CountryCodePK: writer.String("PK"); break;
            case CountryCodePW: writer.String("PW"); break;
            case CountryCodePS: writer.String("PS"); break;
            case CountryCodePA: writer.String("PA"); break;
            case CountryCodePG: writer.String("PG"); break;
            case CountryCodePY: writer.String("PY"); break;
            case CountryCodePE: writer.String("PE"); break;
            case CountryCodePH: writer.String("PH"); break;
            case CountryCodePN: writer.String("PN"); break;
            case CountryCodePL: writer.String("PL"); break;
            case CountryCodePT: writer.String("PT"); break;
            case CountryCodePR: writer.String("PR"); break;
            case CountryCodeQA: writer.String("QA"); break;
            case CountryCodeRE: writer.String("RE"); break;
            case CountryCodeRO: writer.String("RO"); break;
            case CountryCodeRU: writer.String("RU"); break;
            case CountryCodeRW: writer.String("RW"); break;
            case CountryCodeBL: writer.String("BL"); break;
            case CountryCodeSH: writer.String("SH"); break;
            case CountryCodeKN: writer.String("KN"); break;
            case CountryCodeLC: writer.String("LC"); break;
            case CountryCodeMF: writer.String("MF"); break;
            case CountryCodePM: writer.String("PM"); break;
            case CountryCodeVC: writer.String("VC"); break;
            case CountryCodeWS: writer.String("WS"); break;
            case CountryCodeSM: writer.String("SM"); break;
            case CountryCodeST: writer.String("ST"); break;
            case CountryCodeSA: writer.String("SA"); break;
            case CountryCodeSN: writer.String("SN"); break;
            case CountryCodeRS: writer.String("RS"); break;
            case CountryCodeSC: writer.String("SC"); break;
            case CountryCodeSL: writer.String("SL"); break;
            case CountryCodeSG: writer.String("SG"); break;
            case CountryCodeSX: writer.String("SX"); break;
            case CountryCodeSK: writer.String("SK"); break;
            case CountryCodeSI: writer.String("SI"); break;
            case CountryCodeSB: writer.String("SB"); break;
            case CountryCodeSO: writer.String("SO"); break;
            case CountryCodeZA: writer.String("ZA"); break;
            case CountryCodeGS: writer.String("GS"); break;
            case CountryCodeSS: writer.String("SS"); break;
            case CountryCodeES: writer.String("ES"); break;
            case CountryCodeLK: writer.String("LK"); break;
            case CountryCodeSD: writer.String("SD"); break;
            case CountryCodeSR: writer.String("SR"); break;
            case CountryCodeSJ: writer.String("SJ"); break;
            case CountryCodeSZ: writer.String("SZ"); break;
            case CountryCodeSE: writer.String("SE"); break;
            case CountryCodeCH: writer.String("CH"); break;
            case CountryCodeSY: writer.String("SY"); break;
            case CountryCodeTW: writer.String("TW"); break;
            case CountryCodeTJ: writer.String("TJ"); break;
            case CountryCodeTZ: writer.String("TZ"); break;
            case CountryCodeTH: writer.String("TH"); break;
            case CountryCodeTL: writer.String("TL"); break;
            case CountryCodeTG: writer.String("TG"); break;
            case CountryCodeTK: writer.String("TK"); break;
            case CountryCodeTO: writer.String("TO"); break;
            case CountryCodeTT: writer.String("TT"); break;
            case CountryCodeTN: writer.String("TN"); break;
            case CountryCodeTR: writer.String("TR"); break;
            case CountryCodeTM: writer.String("TM"); break;
            case CountryCodeTC: writer.String("TC"); break;
            case CountryCodeTV: writer.String("TV"); break;
            case CountryCodeUG: writer.String("UG"); break;
            case CountryCodeUA: writer.String("UA"); break;
            case CountryCodeAE: writer.String("AE"); break;
            case CountryCodeGB: writer.String("GB"); break;
            case CountryCodeUS: writer.String("US"); break;
            case CountryCodeUM: writer.String("UM"); break;
            case CountryCodeUY: writer.String("UY"); break;
            case CountryCodeUZ: writer.String("UZ"); break;
            case CountryCodeVU: writer.String("VU"); break;
            case CountryCodeVE: writer.String("VE"); break;
            case CountryCodeVN: writer.String("VN"); break;
            case CountryCodeVG: writer.String("VG"); break;
            case CountryCodeVI: writer.String("VI"); break;
            case CountryCodeWF: writer.String("WF"); break;
            case CountryCodeEH: writer.String("EH"); break;
            case CountryCodeYE: writer.String("YE"); break;
            case CountryCodeZM: writer.String("ZM"); break;
            case CountryCodeZW: writer.String("ZW"); break;

            }
        }

        inline CountryCode readCountryCodeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<CountryCode>(obj.GetInt());

            static std::map<const char *, CountryCode, PlayFabClientSdk::StringCompare> _CountryCodeMap;
            if (_CountryCodeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CountryCodeMap["AF"] = CountryCodeAF;
                _CountryCodeMap["AX"] = CountryCodeAX;
                _CountryCodeMap["AL"] = CountryCodeAL;
                _CountryCodeMap["DZ"] = CountryCodeDZ;
                _CountryCodeMap["AS"] = CountryCodeAS;
                _CountryCodeMap["AD"] = CountryCodeAD;
                _CountryCodeMap["AO"] = CountryCodeAO;
                _CountryCodeMap["AI"] = CountryCodeAI;
                _CountryCodeMap["AQ"] = CountryCodeAQ;
                _CountryCodeMap["AG"] = CountryCodeAG;
                _CountryCodeMap["AR"] = CountryCodeAR;
                _CountryCodeMap["AM"] = CountryCodeAM;
                _CountryCodeMap["AW"] = CountryCodeAW;
                _CountryCodeMap["AU"] = CountryCodeAU;
                _CountryCodeMap["AT"] = CountryCodeAT;
                _CountryCodeMap["AZ"] = CountryCodeAZ;
                _CountryCodeMap["BS"] = CountryCodeBS;
                _CountryCodeMap["BH"] = CountryCodeBH;
                _CountryCodeMap["BD"] = CountryCodeBD;
                _CountryCodeMap["BB"] = CountryCodeBB;
                _CountryCodeMap["BY"] = CountryCodeBY;
                _CountryCodeMap["BE"] = CountryCodeBE;
                _CountryCodeMap["BZ"] = CountryCodeBZ;
                _CountryCodeMap["BJ"] = CountryCodeBJ;
                _CountryCodeMap["BM"] = CountryCodeBM;
                _CountryCodeMap["BT"] = CountryCodeBT;
                _CountryCodeMap["BO"] = CountryCodeBO;
                _CountryCodeMap["BQ"] = CountryCodeBQ;
                _CountryCodeMap["BA"] = CountryCodeBA;
                _CountryCodeMap["BW"] = CountryCodeBW;
                _CountryCodeMap["BV"] = CountryCodeBV;
                _CountryCodeMap["BR"] = CountryCodeBR;
                _CountryCodeMap["IO"] = CountryCodeIO;
                _CountryCodeMap["BN"] = CountryCodeBN;
                _CountryCodeMap["BG"] = CountryCodeBG;
                _CountryCodeMap["BF"] = CountryCodeBF;
                _CountryCodeMap["BI"] = CountryCodeBI;
                _CountryCodeMap["KH"] = CountryCodeKH;
                _CountryCodeMap["CM"] = CountryCodeCM;
                _CountryCodeMap["CA"] = CountryCodeCA;
                _CountryCodeMap["CV"] = CountryCodeCV;
                _CountryCodeMap["KY"] = CountryCodeKY;
                _CountryCodeMap["CF"] = CountryCodeCF;
                _CountryCodeMap["TD"] = CountryCodeTD;
                _CountryCodeMap["CL"] = CountryCodeCL;
                _CountryCodeMap["CN"] = CountryCodeCN;
                _CountryCodeMap["CX"] = CountryCodeCX;
                _CountryCodeMap["CC"] = CountryCodeCC;
                _CountryCodeMap["CO"] = CountryCodeCO;
                _CountryCodeMap["KM"] = CountryCodeKM;
                _CountryCodeMap["CG"] = CountryCodeCG;
                _CountryCodeMap["CD"] = CountryCodeCD;
                _CountryCodeMap["CK"] = CountryCodeCK;
                _CountryCodeMap["CR"] = CountryCodeCR;
                _CountryCodeMap["CI"] = CountryCodeCI;
                _CountryCodeMap["HR"] = CountryCodeHR;
                _CountryCodeMap["CU"] = CountryCodeCU;
                _CountryCodeMap["CW"] = CountryCodeCW;
                _CountryCodeMap["CY"] = CountryCodeCY;
                _CountryCodeMap["CZ"] = CountryCodeCZ;
                _CountryCodeMap["DK"] = CountryCodeDK;
                _CountryCodeMap["DJ"] = CountryCodeDJ;
                _CountryCodeMap["DM"] = CountryCodeDM;
                _CountryCodeMap["DO"] = CountryCodeDO;
                _CountryCodeMap["EC"] = CountryCodeEC;
                _CountryCodeMap["EG"] = CountryCodeEG;
                _CountryCodeMap["SV"] = CountryCodeSV;
                _CountryCodeMap["GQ"] = CountryCodeGQ;
                _CountryCodeMap["ER"] = CountryCodeER;
                _CountryCodeMap["EE"] = CountryCodeEE;
                _CountryCodeMap["ET"] = CountryCodeET;
                _CountryCodeMap["FK"] = CountryCodeFK;
                _CountryCodeMap["FO"] = CountryCodeFO;
                _CountryCodeMap["FJ"] = CountryCodeFJ;
                _CountryCodeMap["FI"] = CountryCodeFI;
                _CountryCodeMap["FR"] = CountryCodeFR;
                _CountryCodeMap["GF"] = CountryCodeGF;
                _CountryCodeMap["PF"] = CountryCodePF;
                _CountryCodeMap["TF"] = CountryCodeTF;
                _CountryCodeMap["GA"] = CountryCodeGA;
                _CountryCodeMap["GM"] = CountryCodeGM;
                _CountryCodeMap["GE"] = CountryCodeGE;
                _CountryCodeMap["DE"] = CountryCodeDE;
                _CountryCodeMap["GH"] = CountryCodeGH;
                _CountryCodeMap["GI"] = CountryCodeGI;
                _CountryCodeMap["GR"] = CountryCodeGR;
                _CountryCodeMap["GL"] = CountryCodeGL;
                _CountryCodeMap["GD"] = CountryCodeGD;
                _CountryCodeMap["GP"] = CountryCodeGP;
                _CountryCodeMap["GU"] = CountryCodeGU;
                _CountryCodeMap["GT"] = CountryCodeGT;
                _CountryCodeMap["GG"] = CountryCodeGG;
                _CountryCodeMap["GN"] = CountryCodeGN;
                _CountryCodeMap["GW"] = CountryCodeGW;
                _CountryCodeMap["GY"] = CountryCodeGY;
                _CountryCodeMap["HT"] = CountryCodeHT;
                _CountryCodeMap["HM"] = CountryCodeHM;
                _CountryCodeMap["VA"] = CountryCodeVA;
                _CountryCodeMap["HN"] = CountryCodeHN;
                _CountryCodeMap["HK"] = CountryCodeHK;
                _CountryCodeMap["HU"] = CountryCodeHU;
                _CountryCodeMap["IS"] = CountryCodeIS;
                _CountryCodeMap["IN"] = CountryCodeIN;
                _CountryCodeMap["ID"] = CountryCodeID;
                _CountryCodeMap["IR"] = CountryCodeIR;
                _CountryCodeMap["IQ"] = CountryCodeIQ;
                _CountryCodeMap["IE"] = CountryCodeIE;
                _CountryCodeMap["IM"] = CountryCodeIM;
                _CountryCodeMap["IL"] = CountryCodeIL;
                _CountryCodeMap["IT"] = CountryCodeIT;
                _CountryCodeMap["JM"] = CountryCodeJM;
                _CountryCodeMap["JP"] = CountryCodeJP;
                _CountryCodeMap["JE"] = CountryCodeJE;
                _CountryCodeMap["JO"] = CountryCodeJO;
                _CountryCodeMap["KZ"] = CountryCodeKZ;
                _CountryCodeMap["KE"] = CountryCodeKE;
                _CountryCodeMap["KI"] = CountryCodeKI;
                _CountryCodeMap["KP"] = CountryCodeKP;
                _CountryCodeMap["KR"] = CountryCodeKR;
                _CountryCodeMap["KW"] = CountryCodeKW;
                _CountryCodeMap["KG"] = CountryCodeKG;
                _CountryCodeMap["LA"] = CountryCodeLA;
                _CountryCodeMap["LV"] = CountryCodeLV;
                _CountryCodeMap["LB"] = CountryCodeLB;
                _CountryCodeMap["LS"] = CountryCodeLS;
                _CountryCodeMap["LR"] = CountryCodeLR;
                _CountryCodeMap["LY"] = CountryCodeLY;
                _CountryCodeMap["LI"] = CountryCodeLI;
                _CountryCodeMap["LT"] = CountryCodeLT;
                _CountryCodeMap["LU"] = CountryCodeLU;
                _CountryCodeMap["MO"] = CountryCodeMO;
                _CountryCodeMap["MK"] = CountryCodeMK;
                _CountryCodeMap["MG"] = CountryCodeMG;
                _CountryCodeMap["MW"] = CountryCodeMW;
                _CountryCodeMap["MY"] = CountryCodeMY;
                _CountryCodeMap["MV"] = CountryCodeMV;
                _CountryCodeMap["ML"] = CountryCodeML;
                _CountryCodeMap["MT"] = CountryCodeMT;
                _CountryCodeMap["MH"] = CountryCodeMH;
                _CountryCodeMap["MQ"] = CountryCodeMQ;
                _CountryCodeMap["MR"] = CountryCodeMR;
                _CountryCodeMap["MU"] = CountryCodeMU;
                _CountryCodeMap["YT"] = CountryCodeYT;
                _CountryCodeMap["MX"] = CountryCodeMX;
                _CountryCodeMap["FM"] = CountryCodeFM;
                _CountryCodeMap["MD"] = CountryCodeMD;
                _CountryCodeMap["MC"] = CountryCodeMC;
                _CountryCodeMap["MN"] = CountryCodeMN;
                _CountryCodeMap["ME"] = CountryCodeME;
                _CountryCodeMap["MS"] = CountryCodeMS;
                _CountryCodeMap["MA"] = CountryCodeMA;
                _CountryCodeMap["MZ"] = CountryCodeMZ;
                _CountryCodeMap["MM"] = CountryCodeMM;
                _CountryCodeMap["NA"] = CountryCodeNA;
                _CountryCodeMap["NR"] = CountryCodeNR;
                _CountryCodeMap["NP"] = CountryCodeNP;
                _CountryCodeMap["NL"] = CountryCodeNL;
                _CountryCodeMap["NC"] = CountryCodeNC;
                _CountryCodeMap["NZ"] = CountryCodeNZ;
                _CountryCodeMap["NI"] = CountryCodeNI;
                _CountryCodeMap["NE"] = CountryCodeNE;
                _CountryCodeMap["NG"] = CountryCodeNG;
                _CountryCodeMap["NU"] = CountryCodeNU;
                _CountryCodeMap["NF"] = CountryCodeNF;
                _CountryCodeMap["MP"] = CountryCodeMP;
                _CountryCodeMap["NO"] = CountryCodeNO;
                _CountryCodeMap["OM"] = CountryCodeOM;
                _CountryCodeMap["PK"] = CountryCodePK;
                _CountryCodeMap["PW"] = CountryCodePW;
                _CountryCodeMap["PS"] = CountryCodePS;
                _CountryCodeMap["PA"] = CountryCodePA;
                _CountryCodeMap["PG"] = CountryCodePG;
                _CountryCodeMap["PY"] = CountryCodePY;
                _CountryCodeMap["PE"] = CountryCodePE;
                _CountryCodeMap["PH"] = CountryCodePH;
                _CountryCodeMap["PN"] = CountryCodePN;
                _CountryCodeMap["PL"] = CountryCodePL;
                _CountryCodeMap["PT"] = CountryCodePT;
                _CountryCodeMap["PR"] = CountryCodePR;
                _CountryCodeMap["QA"] = CountryCodeQA;
                _CountryCodeMap["RE"] = CountryCodeRE;
                _CountryCodeMap["RO"] = CountryCodeRO;
                _CountryCodeMap["RU"] = CountryCodeRU;
                _CountryCodeMap["RW"] = CountryCodeRW;
                _CountryCodeMap["BL"] = CountryCodeBL;
                _CountryCodeMap["SH"] = CountryCodeSH;
                _CountryCodeMap["KN"] = CountryCodeKN;
                _CountryCodeMap["LC"] = CountryCodeLC;
                _CountryCodeMap["MF"] = CountryCodeMF;
                _CountryCodeMap["PM"] = CountryCodePM;
                _CountryCodeMap["VC"] = CountryCodeVC;
                _CountryCodeMap["WS"] = CountryCodeWS;
                _CountryCodeMap["SM"] = CountryCodeSM;
                _CountryCodeMap["ST"] = CountryCodeST;
                _CountryCodeMap["SA"] = CountryCodeSA;
                _CountryCodeMap["SN"] = CountryCodeSN;
                _CountryCodeMap["RS"] = CountryCodeRS;
                _CountryCodeMap["SC"] = CountryCodeSC;
                _CountryCodeMap["SL"] = CountryCodeSL;
                _CountryCodeMap["SG"] = CountryCodeSG;
                _CountryCodeMap["SX"] = CountryCodeSX;
                _CountryCodeMap["SK"] = CountryCodeSK;
                _CountryCodeMap["SI"] = CountryCodeSI;
                _CountryCodeMap["SB"] = CountryCodeSB;
                _CountryCodeMap["SO"] = CountryCodeSO;
                _CountryCodeMap["ZA"] = CountryCodeZA;
                _CountryCodeMap["GS"] = CountryCodeGS;
                _CountryCodeMap["SS"] = CountryCodeSS;
                _CountryCodeMap["ES"] = CountryCodeES;
                _CountryCodeMap["LK"] = CountryCodeLK;
                _CountryCodeMap["SD"] = CountryCodeSD;
                _CountryCodeMap["SR"] = CountryCodeSR;
                _CountryCodeMap["SJ"] = CountryCodeSJ;
                _CountryCodeMap["SZ"] = CountryCodeSZ;
                _CountryCodeMap["SE"] = CountryCodeSE;
                _CountryCodeMap["CH"] = CountryCodeCH;
                _CountryCodeMap["SY"] = CountryCodeSY;
                _CountryCodeMap["TW"] = CountryCodeTW;
                _CountryCodeMap["TJ"] = CountryCodeTJ;
                _CountryCodeMap["TZ"] = CountryCodeTZ;
                _CountryCodeMap["TH"] = CountryCodeTH;
                _CountryCodeMap["TL"] = CountryCodeTL;
                _CountryCodeMap["TG"] = CountryCodeTG;
                _CountryCodeMap["TK"] = CountryCodeTK;
                _CountryCodeMap["TO"] = CountryCodeTO;
                _CountryCodeMap["TT"] = CountryCodeTT;
                _CountryCodeMap["TN"] = CountryCodeTN;
                _CountryCodeMap["TR"] = CountryCodeTR;
                _CountryCodeMap["TM"] = CountryCodeTM;
                _CountryCodeMap["TC"] = CountryCodeTC;
                _CountryCodeMap["TV"] = CountryCodeTV;
                _CountryCodeMap["UG"] = CountryCodeUG;
                _CountryCodeMap["UA"] = CountryCodeUA;
                _CountryCodeMap["AE"] = CountryCodeAE;
                _CountryCodeMap["GB"] = CountryCodeGB;
                _CountryCodeMap["US"] = CountryCodeUS;
                _CountryCodeMap["UM"] = CountryCodeUM;
                _CountryCodeMap["UY"] = CountryCodeUY;
                _CountryCodeMap["UZ"] = CountryCodeUZ;
                _CountryCodeMap["VU"] = CountryCodeVU;
                _CountryCodeMap["VE"] = CountryCodeVE;
                _CountryCodeMap["VN"] = CountryCodeVN;
                _CountryCodeMap["VG"] = CountryCodeVG;
                _CountryCodeMap["VI"] = CountryCodeVI;
                _CountryCodeMap["WF"] = CountryCodeWF;
                _CountryCodeMap["EH"] = CountryCodeEH;
                _CountryCodeMap["YE"] = CountryCodeYE;
                _CountryCodeMap["ZM"] = CountryCodeZM;
                _CountryCodeMap["ZW"] = CountryCodeZW;

            }

            auto output = _CountryCodeMap.find(obj.GetString());
            if (output != _CountryCodeMap.end())
                return output->second;

            return CountryCodeAF; // Basically critical fail
        }

        struct CreateSharedGroupRequest : public PlayFabBaseModel
        {
            AZStd::string SharedGroupId;

            CreateSharedGroupRequest() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupRequest(const CreateSharedGroupRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupRequest(const rapidjson::Value& obj) : CreateSharedGroupRequest()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (SharedGroupId.length() > 0) {
                    writer.String("SharedGroupId");
                    writer.String(SharedGroupId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct CreateSharedGroupResult : public PlayFabBaseModel
        {
            AZStd::string SharedGroupId;

            CreateSharedGroupResult() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupResult(const CreateSharedGroupResult& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupResult(const rapidjson::Value& obj) : CreateSharedGroupResult()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (SharedGroupId.length() > 0) {
                    writer.String("SharedGroupId");
                    writer.String(SharedGroupId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        inline void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CurrencyAED: writer.String("AED"); break;
            case CurrencyAFN: writer.String("AFN"); break;
            case CurrencyALL: writer.String("ALL"); break;
            case CurrencyAMD: writer.String("AMD"); break;
            case CurrencyANG: writer.String("ANG"); break;
            case CurrencyAOA: writer.String("AOA"); break;
            case CurrencyARS: writer.String("ARS"); break;
            case CurrencyAUD: writer.String("AUD"); break;
            case CurrencyAWG: writer.String("AWG"); break;
            case CurrencyAZN: writer.String("AZN"); break;
            case CurrencyBAM: writer.String("BAM"); break;
            case CurrencyBBD: writer.String("BBD"); break;
            case CurrencyBDT: writer.String("BDT"); break;
            case CurrencyBGN: writer.String("BGN"); break;
            case CurrencyBHD: writer.String("BHD"); break;
            case CurrencyBIF: writer.String("BIF"); break;
            case CurrencyBMD: writer.String("BMD"); break;
            case CurrencyBND: writer.String("BND"); break;
            case CurrencyBOB: writer.String("BOB"); break;
            case CurrencyBRL: writer.String("BRL"); break;
            case CurrencyBSD: writer.String("BSD"); break;
            case CurrencyBTN: writer.String("BTN"); break;
            case CurrencyBWP: writer.String("BWP"); break;
            case CurrencyBYR: writer.String("BYR"); break;
            case CurrencyBZD: writer.String("BZD"); break;
            case CurrencyCAD: writer.String("CAD"); break;
            case CurrencyCDF: writer.String("CDF"); break;
            case CurrencyCHF: writer.String("CHF"); break;
            case CurrencyCLP: writer.String("CLP"); break;
            case CurrencyCNY: writer.String("CNY"); break;
            case CurrencyCOP: writer.String("COP"); break;
            case CurrencyCRC: writer.String("CRC"); break;
            case CurrencyCUC: writer.String("CUC"); break;
            case CurrencyCUP: writer.String("CUP"); break;
            case CurrencyCVE: writer.String("CVE"); break;
            case CurrencyCZK: writer.String("CZK"); break;
            case CurrencyDJF: writer.String("DJF"); break;
            case CurrencyDKK: writer.String("DKK"); break;
            case CurrencyDOP: writer.String("DOP"); break;
            case CurrencyDZD: writer.String("DZD"); break;
            case CurrencyEGP: writer.String("EGP"); break;
            case CurrencyERN: writer.String("ERN"); break;
            case CurrencyETB: writer.String("ETB"); break;
            case CurrencyEUR: writer.String("EUR"); break;
            case CurrencyFJD: writer.String("FJD"); break;
            case CurrencyFKP: writer.String("FKP"); break;
            case CurrencyGBP: writer.String("GBP"); break;
            case CurrencyGEL: writer.String("GEL"); break;
            case CurrencyGGP: writer.String("GGP"); break;
            case CurrencyGHS: writer.String("GHS"); break;
            case CurrencyGIP: writer.String("GIP"); break;
            case CurrencyGMD: writer.String("GMD"); break;
            case CurrencyGNF: writer.String("GNF"); break;
            case CurrencyGTQ: writer.String("GTQ"); break;
            case CurrencyGYD: writer.String("GYD"); break;
            case CurrencyHKD: writer.String("HKD"); break;
            case CurrencyHNL: writer.String("HNL"); break;
            case CurrencyHRK: writer.String("HRK"); break;
            case CurrencyHTG: writer.String("HTG"); break;
            case CurrencyHUF: writer.String("HUF"); break;
            case CurrencyIDR: writer.String("IDR"); break;
            case CurrencyILS: writer.String("ILS"); break;
            case CurrencyIMP: writer.String("IMP"); break;
            case CurrencyINR: writer.String("INR"); break;
            case CurrencyIQD: writer.String("IQD"); break;
            case CurrencyIRR: writer.String("IRR"); break;
            case CurrencyISK: writer.String("ISK"); break;
            case CurrencyJEP: writer.String("JEP"); break;
            case CurrencyJMD: writer.String("JMD"); break;
            case CurrencyJOD: writer.String("JOD"); break;
            case CurrencyJPY: writer.String("JPY"); break;
            case CurrencyKES: writer.String("KES"); break;
            case CurrencyKGS: writer.String("KGS"); break;
            case CurrencyKHR: writer.String("KHR"); break;
            case CurrencyKMF: writer.String("KMF"); break;
            case CurrencyKPW: writer.String("KPW"); break;
            case CurrencyKRW: writer.String("KRW"); break;
            case CurrencyKWD: writer.String("KWD"); break;
            case CurrencyKYD: writer.String("KYD"); break;
            case CurrencyKZT: writer.String("KZT"); break;
            case CurrencyLAK: writer.String("LAK"); break;
            case CurrencyLBP: writer.String("LBP"); break;
            case CurrencyLKR: writer.String("LKR"); break;
            case CurrencyLRD: writer.String("LRD"); break;
            case CurrencyLSL: writer.String("LSL"); break;
            case CurrencyLYD: writer.String("LYD"); break;
            case CurrencyMAD: writer.String("MAD"); break;
            case CurrencyMDL: writer.String("MDL"); break;
            case CurrencyMGA: writer.String("MGA"); break;
            case CurrencyMKD: writer.String("MKD"); break;
            case CurrencyMMK: writer.String("MMK"); break;
            case CurrencyMNT: writer.String("MNT"); break;
            case CurrencyMOP: writer.String("MOP"); break;
            case CurrencyMRO: writer.String("MRO"); break;
            case CurrencyMUR: writer.String("MUR"); break;
            case CurrencyMVR: writer.String("MVR"); break;
            case CurrencyMWK: writer.String("MWK"); break;
            case CurrencyMXN: writer.String("MXN"); break;
            case CurrencyMYR: writer.String("MYR"); break;
            case CurrencyMZN: writer.String("MZN"); break;
            case CurrencyNAD: writer.String("NAD"); break;
            case CurrencyNGN: writer.String("NGN"); break;
            case CurrencyNIO: writer.String("NIO"); break;
            case CurrencyNOK: writer.String("NOK"); break;
            case CurrencyNPR: writer.String("NPR"); break;
            case CurrencyNZD: writer.String("NZD"); break;
            case CurrencyOMR: writer.String("OMR"); break;
            case CurrencyPAB: writer.String("PAB"); break;
            case CurrencyPEN: writer.String("PEN"); break;
            case CurrencyPGK: writer.String("PGK"); break;
            case CurrencyPHP: writer.String("PHP"); break;
            case CurrencyPKR: writer.String("PKR"); break;
            case CurrencyPLN: writer.String("PLN"); break;
            case CurrencyPYG: writer.String("PYG"); break;
            case CurrencyQAR: writer.String("QAR"); break;
            case CurrencyRON: writer.String("RON"); break;
            case CurrencyRSD: writer.String("RSD"); break;
            case CurrencyRUB: writer.String("RUB"); break;
            case CurrencyRWF: writer.String("RWF"); break;
            case CurrencySAR: writer.String("SAR"); break;
            case CurrencySBD: writer.String("SBD"); break;
            case CurrencySCR: writer.String("SCR"); break;
            case CurrencySDG: writer.String("SDG"); break;
            case CurrencySEK: writer.String("SEK"); break;
            case CurrencySGD: writer.String("SGD"); break;
            case CurrencySHP: writer.String("SHP"); break;
            case CurrencySLL: writer.String("SLL"); break;
            case CurrencySOS: writer.String("SOS"); break;
            case CurrencySPL: writer.String("SPL"); break;
            case CurrencySRD: writer.String("SRD"); break;
            case CurrencySTD: writer.String("STD"); break;
            case CurrencySVC: writer.String("SVC"); break;
            case CurrencySYP: writer.String("SYP"); break;
            case CurrencySZL: writer.String("SZL"); break;
            case CurrencyTHB: writer.String("THB"); break;
            case CurrencyTJS: writer.String("TJS"); break;
            case CurrencyTMT: writer.String("TMT"); break;
            case CurrencyTND: writer.String("TND"); break;
            case CurrencyTOP: writer.String("TOP"); break;
            case CurrencyTRY: writer.String("TRY"); break;
            case CurrencyTTD: writer.String("TTD"); break;
            case CurrencyTVD: writer.String("TVD"); break;
            case CurrencyTWD: writer.String("TWD"); break;
            case CurrencyTZS: writer.String("TZS"); break;
            case CurrencyUAH: writer.String("UAH"); break;
            case CurrencyUGX: writer.String("UGX"); break;
            case CurrencyUSD: writer.String("USD"); break;
            case CurrencyUYU: writer.String("UYU"); break;
            case CurrencyUZS: writer.String("UZS"); break;
            case CurrencyVEF: writer.String("VEF"); break;
            case CurrencyVND: writer.String("VND"); break;
            case CurrencyVUV: writer.String("VUV"); break;
            case CurrencyWST: writer.String("WST"); break;
            case CurrencyXAF: writer.String("XAF"); break;
            case CurrencyXCD: writer.String("XCD"); break;
            case CurrencyXDR: writer.String("XDR"); break;
            case CurrencyXOF: writer.String("XOF"); break;
            case CurrencyXPF: writer.String("XPF"); break;
            case CurrencyYER: writer.String("YER"); break;
            case CurrencyZAR: writer.String("ZAR"); break;
            case CurrencyZMW: writer.String("ZMW"); break;
            case CurrencyZWD: writer.String("ZWD"); break;

            }
        }

        inline Currency readCurrencyFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<Currency>(obj.GetInt());

            static std::map<const char *, Currency, PlayFabClientSdk::StringCompare> _CurrencyMap;
            if (_CurrencyMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CurrencyMap["AED"] = CurrencyAED;
                _CurrencyMap["AFN"] = CurrencyAFN;
                _CurrencyMap["ALL"] = CurrencyALL;
                _CurrencyMap["AMD"] = CurrencyAMD;
                _CurrencyMap["ANG"] = CurrencyANG;
                _CurrencyMap["AOA"] = CurrencyAOA;
                _CurrencyMap["ARS"] = CurrencyARS;
                _CurrencyMap["AUD"] = CurrencyAUD;
                _CurrencyMap["AWG"] = CurrencyAWG;
                _CurrencyMap["AZN"] = CurrencyAZN;
                _CurrencyMap["BAM"] = CurrencyBAM;
                _CurrencyMap["BBD"] = CurrencyBBD;
                _CurrencyMap["BDT"] = CurrencyBDT;
                _CurrencyMap["BGN"] = CurrencyBGN;
                _CurrencyMap["BHD"] = CurrencyBHD;
                _CurrencyMap["BIF"] = CurrencyBIF;
                _CurrencyMap["BMD"] = CurrencyBMD;
                _CurrencyMap["BND"] = CurrencyBND;
                _CurrencyMap["BOB"] = CurrencyBOB;
                _CurrencyMap["BRL"] = CurrencyBRL;
                _CurrencyMap["BSD"] = CurrencyBSD;
                _CurrencyMap["BTN"] = CurrencyBTN;
                _CurrencyMap["BWP"] = CurrencyBWP;
                _CurrencyMap["BYR"] = CurrencyBYR;
                _CurrencyMap["BZD"] = CurrencyBZD;
                _CurrencyMap["CAD"] = CurrencyCAD;
                _CurrencyMap["CDF"] = CurrencyCDF;
                _CurrencyMap["CHF"] = CurrencyCHF;
                _CurrencyMap["CLP"] = CurrencyCLP;
                _CurrencyMap["CNY"] = CurrencyCNY;
                _CurrencyMap["COP"] = CurrencyCOP;
                _CurrencyMap["CRC"] = CurrencyCRC;
                _CurrencyMap["CUC"] = CurrencyCUC;
                _CurrencyMap["CUP"] = CurrencyCUP;
                _CurrencyMap["CVE"] = CurrencyCVE;
                _CurrencyMap["CZK"] = CurrencyCZK;
                _CurrencyMap["DJF"] = CurrencyDJF;
                _CurrencyMap["DKK"] = CurrencyDKK;
                _CurrencyMap["DOP"] = CurrencyDOP;
                _CurrencyMap["DZD"] = CurrencyDZD;
                _CurrencyMap["EGP"] = CurrencyEGP;
                _CurrencyMap["ERN"] = CurrencyERN;
                _CurrencyMap["ETB"] = CurrencyETB;
                _CurrencyMap["EUR"] = CurrencyEUR;
                _CurrencyMap["FJD"] = CurrencyFJD;
                _CurrencyMap["FKP"] = CurrencyFKP;
                _CurrencyMap["GBP"] = CurrencyGBP;
                _CurrencyMap["GEL"] = CurrencyGEL;
                _CurrencyMap["GGP"] = CurrencyGGP;
                _CurrencyMap["GHS"] = CurrencyGHS;
                _CurrencyMap["GIP"] = CurrencyGIP;
                _CurrencyMap["GMD"] = CurrencyGMD;
                _CurrencyMap["GNF"] = CurrencyGNF;
                _CurrencyMap["GTQ"] = CurrencyGTQ;
                _CurrencyMap["GYD"] = CurrencyGYD;
                _CurrencyMap["HKD"] = CurrencyHKD;
                _CurrencyMap["HNL"] = CurrencyHNL;
                _CurrencyMap["HRK"] = CurrencyHRK;
                _CurrencyMap["HTG"] = CurrencyHTG;
                _CurrencyMap["HUF"] = CurrencyHUF;
                _CurrencyMap["IDR"] = CurrencyIDR;
                _CurrencyMap["ILS"] = CurrencyILS;
                _CurrencyMap["IMP"] = CurrencyIMP;
                _CurrencyMap["INR"] = CurrencyINR;
                _CurrencyMap["IQD"] = CurrencyIQD;
                _CurrencyMap["IRR"] = CurrencyIRR;
                _CurrencyMap["ISK"] = CurrencyISK;
                _CurrencyMap["JEP"] = CurrencyJEP;
                _CurrencyMap["JMD"] = CurrencyJMD;
                _CurrencyMap["JOD"] = CurrencyJOD;
                _CurrencyMap["JPY"] = CurrencyJPY;
                _CurrencyMap["KES"] = CurrencyKES;
                _CurrencyMap["KGS"] = CurrencyKGS;
                _CurrencyMap["KHR"] = CurrencyKHR;
                _CurrencyMap["KMF"] = CurrencyKMF;
                _CurrencyMap["KPW"] = CurrencyKPW;
                _CurrencyMap["KRW"] = CurrencyKRW;
                _CurrencyMap["KWD"] = CurrencyKWD;
                _CurrencyMap["KYD"] = CurrencyKYD;
                _CurrencyMap["KZT"] = CurrencyKZT;
                _CurrencyMap["LAK"] = CurrencyLAK;
                _CurrencyMap["LBP"] = CurrencyLBP;
                _CurrencyMap["LKR"] = CurrencyLKR;
                _CurrencyMap["LRD"] = CurrencyLRD;
                _CurrencyMap["LSL"] = CurrencyLSL;
                _CurrencyMap["LYD"] = CurrencyLYD;
                _CurrencyMap["MAD"] = CurrencyMAD;
                _CurrencyMap["MDL"] = CurrencyMDL;
                _CurrencyMap["MGA"] = CurrencyMGA;
                _CurrencyMap["MKD"] = CurrencyMKD;
                _CurrencyMap["MMK"] = CurrencyMMK;
                _CurrencyMap["MNT"] = CurrencyMNT;
                _CurrencyMap["MOP"] = CurrencyMOP;
                _CurrencyMap["MRO"] = CurrencyMRO;
                _CurrencyMap["MUR"] = CurrencyMUR;
                _CurrencyMap["MVR"] = CurrencyMVR;
                _CurrencyMap["MWK"] = CurrencyMWK;
                _CurrencyMap["MXN"] = CurrencyMXN;
                _CurrencyMap["MYR"] = CurrencyMYR;
                _CurrencyMap["MZN"] = CurrencyMZN;
                _CurrencyMap["NAD"] = CurrencyNAD;
                _CurrencyMap["NGN"] = CurrencyNGN;
                _CurrencyMap["NIO"] = CurrencyNIO;
                _CurrencyMap["NOK"] = CurrencyNOK;
                _CurrencyMap["NPR"] = CurrencyNPR;
                _CurrencyMap["NZD"] = CurrencyNZD;
                _CurrencyMap["OMR"] = CurrencyOMR;
                _CurrencyMap["PAB"] = CurrencyPAB;
                _CurrencyMap["PEN"] = CurrencyPEN;
                _CurrencyMap["PGK"] = CurrencyPGK;
                _CurrencyMap["PHP"] = CurrencyPHP;
                _CurrencyMap["PKR"] = CurrencyPKR;
                _CurrencyMap["PLN"] = CurrencyPLN;
                _CurrencyMap["PYG"] = CurrencyPYG;
                _CurrencyMap["QAR"] = CurrencyQAR;
                _CurrencyMap["RON"] = CurrencyRON;
                _CurrencyMap["RSD"] = CurrencyRSD;
                _CurrencyMap["RUB"] = CurrencyRUB;
                _CurrencyMap["RWF"] = CurrencyRWF;
                _CurrencyMap["SAR"] = CurrencySAR;
                _CurrencyMap["SBD"] = CurrencySBD;
                _CurrencyMap["SCR"] = CurrencySCR;
                _CurrencyMap["SDG"] = CurrencySDG;
                _CurrencyMap["SEK"] = CurrencySEK;
                _CurrencyMap["SGD"] = CurrencySGD;
                _CurrencyMap["SHP"] = CurrencySHP;
                _CurrencyMap["SLL"] = CurrencySLL;
                _CurrencyMap["SOS"] = CurrencySOS;
                _CurrencyMap["SPL"] = CurrencySPL;
                _CurrencyMap["SRD"] = CurrencySRD;
                _CurrencyMap["STD"] = CurrencySTD;
                _CurrencyMap["SVC"] = CurrencySVC;
                _CurrencyMap["SYP"] = CurrencySYP;
                _CurrencyMap["SZL"] = CurrencySZL;
                _CurrencyMap["THB"] = CurrencyTHB;
                _CurrencyMap["TJS"] = CurrencyTJS;
                _CurrencyMap["TMT"] = CurrencyTMT;
                _CurrencyMap["TND"] = CurrencyTND;
                _CurrencyMap["TOP"] = CurrencyTOP;
                _CurrencyMap["TRY"] = CurrencyTRY;
                _CurrencyMap["TTD"] = CurrencyTTD;
                _CurrencyMap["TVD"] = CurrencyTVD;
                _CurrencyMap["TWD"] = CurrencyTWD;
                _CurrencyMap["TZS"] = CurrencyTZS;
                _CurrencyMap["UAH"] = CurrencyUAH;
                _CurrencyMap["UGX"] = CurrencyUGX;
                _CurrencyMap["USD"] = CurrencyUSD;
                _CurrencyMap["UYU"] = CurrencyUYU;
                _CurrencyMap["UZS"] = CurrencyUZS;
                _CurrencyMap["VEF"] = CurrencyVEF;
                _CurrencyMap["VND"] = CurrencyVND;
                _CurrencyMap["VUV"] = CurrencyVUV;
                _CurrencyMap["WST"] = CurrencyWST;
                _CurrencyMap["XAF"] = CurrencyXAF;
                _CurrencyMap["XCD"] = CurrencyXCD;
                _CurrencyMap["XDR"] = CurrencyXDR;
                _CurrencyMap["XOF"] = CurrencyXOF;
                _CurrencyMap["XPF"] = CurrencyXPF;
                _CurrencyMap["YER"] = CurrencyYER;
                _CurrencyMap["ZAR"] = CurrencyZAR;
                _CurrencyMap["ZMW"] = CurrencyZMW;
                _CurrencyMap["ZWD"] = CurrencyZWD;

            }

            auto output = _CurrencyMap.find(obj.GetString());
            if (output != _CurrencyMap.end())
                return output->second;

            return CurrencyAED; // Basically critical fail
        }

        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        inline void writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case RegionUSCentral: writer.String("USCentral"); break;
            case RegionUSEast: writer.String("USEast"); break;
            case RegionEUWest: writer.String("EUWest"); break;
            case RegionSingapore: writer.String("Singapore"); break;
            case RegionJapan: writer.String("Japan"); break;
            case RegionBrazil: writer.String("Brazil"); break;
            case RegionAustralia: writer.String("Australia"); break;

            }
        }

        inline Region readRegionFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<Region>(obj.GetInt());

            static std::map<const char *, Region, PlayFabClientSdk::StringCompare> _RegionMap;
            if (_RegionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _RegionMap["USCentral"] = RegionUSCentral;
                _RegionMap["USEast"] = RegionUSEast;
                _RegionMap["EUWest"] = RegionEUWest;
                _RegionMap["Singapore"] = RegionSingapore;
                _RegionMap["Japan"] = RegionJapan;
                _RegionMap["Brazil"] = RegionBrazil;
                _RegionMap["Australia"] = RegionAustralia;

            }

            auto output = _RegionMap.find(obj.GetString());
            if (output != _RegionMap.end())
                return output->second;

            return RegionUSCentral; // Basically critical fail
        }

        struct CurrentGamesRequest : public PlayFabBaseModel
        {
            AZStd::string BuildVersion;
            AZStd::string GameMode;
            Boxed<Region> pfRegion;
            AZStd::string StatisticName;
            CollectionFilter* TagFilter;

            CurrentGamesRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameMode(),
                pfRegion(),
                StatisticName(),
                TagFilter(nullptr)
            {}

            CurrentGamesRequest(const CurrentGamesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter ? new CollectionFilter(*src.TagFilter) : nullptr)
            {}

            CurrentGamesRequest(const rapidjson::Value& obj) : CurrentGamesRequest()
            {
                readFromValue(obj);
            }

            ~CurrentGamesRequest()
            {
                if (TagFilter != nullptr) delete TagFilter;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (BuildVersion.length() > 0) {
                    writer.String("BuildVersion");
                    writer.String(BuildVersion.c_str());
                }
                if (GameMode.length() > 0) {
                    writer.String("GameMode");
                    writer.String(GameMode.c_str());
                }
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                if (TagFilter != nullptr) {
                    writer.String("TagFilter");
                    TagFilter->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator TagFilter_member = obj.FindMember("TagFilter");
                if (TagFilter_member != obj.MemberEnd() && !TagFilter_member->value.IsNull()) TagFilter = new CollectionFilter(TagFilter_member->value);

                return true;
            }
        };

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        inline void writeGameInstanceStateEnumJSON(GameInstanceState enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case GameInstanceStateOpen: writer.String("Open"); break;
            case GameInstanceStateClosed: writer.String("Closed"); break;

            }
        }

        inline GameInstanceState readGameInstanceStateFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<GameInstanceState>(obj.GetInt());

            static std::map<const char *, GameInstanceState, PlayFabClientSdk::StringCompare> _GameInstanceStateMap;
            if (_GameInstanceStateMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _GameInstanceStateMap["Open"] = GameInstanceStateOpen;
                _GameInstanceStateMap["Closed"] = GameInstanceStateClosed;

            }

            auto output = _GameInstanceStateMap.find(obj.GetString());
            if (output != _GameInstanceStateMap.end())
                return output->second;

            return GameInstanceStateOpen; // Basically critical fail
        }

        struct GameInfo : public PlayFabBaseModel
        {
            AZStd::string BuildVersion;
            AZStd::string GameMode;
            AZStd::string GameServerData;
            Boxed<GameInstanceState> GameServerStateEnum;
            OptionalTime LastHeartbeat;
            AZStd::string LobbyID;
            OptionalInt32 MaxPlayers;
            AZStd::vector<AZStd::string> PlayerUserIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<Region> pfRegion;
            Uint32 RunTime;
            AZStd::string ServerHostname;
            AZStd::string ServerIPV6Address;
            OptionalInt32 ServerPort;
            AZStd::string StatisticName;
            std::map<AZStd::string, AZStd::string> Tags;

            GameInfo() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameMode(),
                GameServerData(),
                GameServerStateEnum(),
                LastHeartbeat(),
                LobbyID(),
                MaxPlayers(),
                PlayerUserIds(),
                pfRegion(),
                RunTime(0),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort(),
                StatisticName(),
                Tags()
            {}

            GameInfo(const GameInfo& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                GameServerData(src.GameServerData),
                GameServerStateEnum(src.GameServerStateEnum),
                LastHeartbeat(src.LastHeartbeat),
                LobbyID(src.LobbyID),
                MaxPlayers(src.MaxPlayers),
                PlayerUserIds(src.PlayerUserIds),
                pfRegion(src.pfRegion),
                RunTime(src.RunTime),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                StatisticName(src.StatisticName),
                Tags(src.Tags)
            {}

            GameInfo(const rapidjson::Value& obj) : GameInfo()
            {
                readFromValue(obj);
            }

            ~GameInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (BuildVersion.length() > 0) {
                    writer.String("BuildVersion");
                    writer.String(BuildVersion.c_str());
                }
                if (GameMode.length() > 0) {
                    writer.String("GameMode");
                    writer.String(GameMode.c_str());
                }
                if (GameServerData.length() > 0) {
                    writer.String("GameServerData");
                    writer.String(GameServerData.c_str());
                }
                if (GameServerStateEnum.notNull()) {
                    writer.String("GameServerStateEnum");
                    writeGameInstanceStateEnumJSON(GameServerStateEnum, writer);
                }
                if (LastHeartbeat.notNull()) {
                    writer.String("LastHeartbeat");
                    writeDatetime(LastHeartbeat, writer);
                }
                if (LobbyID.length() > 0) {
                    writer.String("LobbyID");
                    writer.String(LobbyID.c_str());
                }
                if (MaxPlayers.notNull()) {
                    writer.String("MaxPlayers");
                    writer.Int(MaxPlayers);
                }
                if (!PlayerUserIds.empty()) {
                    writer.String("PlayerUserIds");
                    writer.StartArray();
                    for (auto iter = PlayerUserIds.begin(); iter != PlayerUserIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                writer.String("RunTime");
                writer.Uint(RunTime);
                if (ServerHostname.length() > 0) {
                    writer.String("ServerHostname");
                    writer.String(ServerHostname.c_str());
                }
                if (ServerIPV6Address.length() > 0) {
                    writer.String("ServerIPV6Address");
                    writer.String(ServerIPV6Address.c_str());
                }
                if (ServerPort.notNull()) {
                    writer.String("ServerPort");
                    writer.Int(ServerPort);
                }
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartObject();
                    for (auto iter = Tags.begin(); iter != Tags.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator GameServerData_member = obj.FindMember("GameServerData");
                if (GameServerData_member != obj.MemberEnd() && !GameServerData_member->value.IsNull()) GameServerData = GameServerData_member->value.GetString();
                const Value::ConstMemberIterator GameServerStateEnum_member = obj.FindMember("GameServerStateEnum");
                if (GameServerStateEnum_member != obj.MemberEnd() && !GameServerStateEnum_member->value.IsNull()) GameServerStateEnum = readGameInstanceStateFromValue(GameServerStateEnum_member->value);
                const Value::ConstMemberIterator LastHeartbeat_member = obj.FindMember("LastHeartbeat");
                if (LastHeartbeat_member != obj.MemberEnd() && !LastHeartbeat_member->value.IsNull()) LastHeartbeat = readDatetime(LastHeartbeat_member->value);
                const Value::ConstMemberIterator LobbyID_member = obj.FindMember("LobbyID");
                if (LobbyID_member != obj.MemberEnd() && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
                const Value::ConstMemberIterator MaxPlayers_member = obj.FindMember("MaxPlayers");
                if (MaxPlayers_member != obj.MemberEnd() && !MaxPlayers_member->value.IsNull()) MaxPlayers = MaxPlayers_member->value.GetInt();
                const Value::ConstMemberIterator PlayerUserIds_member = obj.FindMember("PlayerUserIds");
                if (PlayerUserIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerUserIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerUserIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator RunTime_member = obj.FindMember("RunTime");
                if (RunTime_member != obj.MemberEnd() && !RunTime_member->value.IsNull()) RunTime = RunTime_member->value.GetUint();
                const Value::ConstMemberIterator ServerHostname_member = obj.FindMember("ServerHostname");
                if (ServerHostname_member != obj.MemberEnd() && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
                const Value::ConstMemberIterator ServerIPV6Address_member = obj.FindMember("ServerIPV6Address");
                if (ServerIPV6Address_member != obj.MemberEnd() && !ServerIPV6Address_member->value.IsNull()) ServerIPV6Address = ServerIPV6Address_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Tags_member->value.MemberBegin(); iter != Tags_member->value.MemberEnd(); ++iter) {
                        Tags[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct CurrentGamesResult : public PlayFabBaseModel
        {
            Int32 GameCount;
            AZStd::vector<GameInfo> Games; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Int32 PlayerCount;

            CurrentGamesResult() :
                PlayFabBaseModel(),
                GameCount(0),
                Games(),
                PlayerCount(0)
            {}

            CurrentGamesResult(const CurrentGamesResult& src) :
                PlayFabBaseModel(),
                GameCount(src.GameCount),
                Games(src.Games),
                PlayerCount(src.PlayerCount)
            {}

            CurrentGamesResult(const rapidjson::Value& obj) : CurrentGamesResult()
            {
                readFromValue(obj);
            }

            ~CurrentGamesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GameCount");
                writer.Int(GameCount);
                if (!Games.empty()) {
                    writer.String("Games");
                    writer.StartArray();
                    for (auto iter = Games.begin(); iter != Games.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("PlayerCount");
                writer.Int(PlayerCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCount_member = obj.FindMember("GameCount");
                if (GameCount_member != obj.MemberEnd() && !GameCount_member->value.IsNull()) GameCount = GameCount_member->value.GetInt();
                const Value::ConstMemberIterator Games_member = obj.FindMember("Games");
                if (Games_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Games_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Games.push_back(GameInfo(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PlayerCount_member = obj.FindMember("PlayerCount");
                if (PlayerCount_member != obj.MemberEnd() && !PlayerCount_member->value.IsNull()) PlayerCount = PlayerCount_member->value.GetInt();

                return true;
            }
        };

        struct DeviceInfoRequest : public PlayFabBaseModel
        {
            std::map<AZStd::string, MultitypeVar> Info;

            DeviceInfoRequest() :
                PlayFabBaseModel(),
                Info()
            {}

            DeviceInfoRequest(const DeviceInfoRequest& src) :
                PlayFabBaseModel(),
                Info(src.Info)
            {}

            DeviceInfoRequest(const rapidjson::Value& obj) : DeviceInfoRequest()
            {
                readFromValue(obj);
            }

            ~DeviceInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Info.empty()) {
                    writer.String("Info");
                    writer.StartObject();
                    for (auto iter = Info.begin(); iter != Info.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Info_member = obj.FindMember("Info");
                if (Info_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Info_member->value.MemberBegin(); iter != Info_member->value.MemberEnd(); ++iter) {
                        Info[iter->name.GetString()] = MultitypeVar(iter->value);
                    }
                }

                return true;
            }
        };

        struct EmptyResult : public PlayFabBaseModel
        {

            EmptyResult() :
                PlayFabBaseModel()
            {}

            EmptyResult(const EmptyResult& src) :
                PlayFabBaseModel()
            {}

            EmptyResult(const rapidjson::Value& obj) : EmptyResult()
            {
                readFromValue(obj);
            }

            ~EmptyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup
        };

        inline void writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EntityTypestitle: writer.String("title"); break;
            case EntityTypesmaster_player_account: writer.String("master_player_account"); break;
            case EntityTypestitle_player_account: writer.String("title_player_account"); break;
            case EntityTypescharacter: writer.String("character"); break;
            case EntityTypesgroup: writer.String("group"); break;

            }
        }

        inline EntityTypes readEntityTypesFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EntityTypes>(obj.GetInt());

            static std::map<const char *, EntityTypes, PlayFabClientSdk::StringCompare> _EntityTypesMap;
            if (_EntityTypesMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EntityTypesMap["title"] = EntityTypestitle;
                _EntityTypesMap["master_player_account"] = EntityTypesmaster_player_account;
                _EntityTypesMap["title_player_account"] = EntityTypestitle_player_account;
                _EntityTypesMap["character"] = EntityTypescharacter;
                _EntityTypesMap["group"] = EntityTypesgroup;

            }

            auto output = _EntityTypesMap.find(obj.GetString());
            if (output != _EntityTypesMap.end())
                return output->second;

            return EntityTypestitle; // Basically critical fail
        }

        struct EntityKey : public PlayFabBaseModel
        {
            AZStd::string Id;
            Boxed<EntityTypes> Type;
            AZStd::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            EntityKey(const rapidjson::Value& obj) : EntityKey()
            {
                readFromValue(obj);
            }

            ~EntityKey()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Id");
                writer.String(Id.c_str());
                if (Type.notNull()) {
                    writer.String("Type");
                    writeEntityTypesEnumJSON(Type, writer);
                }
                if (TypeString.length() > 0) {
                    writer.String("TypeString");
                    writer.String(TypeString.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
                if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = readEntityTypesFromValue(Type_member->value);
                const Value::ConstMemberIterator TypeString_member = obj.FindMember("TypeString");
                if (TypeString_member != obj.MemberEnd() && !TypeString_member->value.IsNull()) TypeString = TypeString_member->value.GetString();

                return true;
            }
        };

        struct EntityTokenResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            AZStd::string EntityToken;
            OptionalTime TokenExpiration;

            EntityTokenResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                EntityToken(),
                TokenExpiration()
            {}

            EntityTokenResponse(const EntityTokenResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            EntityTokenResponse(const rapidjson::Value& obj) : EntityTokenResponse()
            {
                readFromValue(obj);
            }

            ~EntityTokenResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                if (EntityToken.length() > 0) {
                    writer.String("EntityToken");
                    writer.String(EntityToken.c_str());
                }
                if (TokenExpiration.notNull()) {
                    writer.String("TokenExpiration");
                    writeDatetime(TokenExpiration, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator EntityToken_member = obj.FindMember("EntityToken");
                if (EntityToken_member != obj.MemberEnd() && !EntityToken_member->value.IsNull()) EntityToken = EntityToken_member->value.GetString();
                const Value::ConstMemberIterator TokenExpiration_member = obj.FindMember("TokenExpiration");
                if (TokenExpiration_member != obj.MemberEnd() && !TokenExpiration_member->value.IsNull()) TokenExpiration = readDatetime(TokenExpiration_member->value);

                return true;
            }
        };

        struct ExecuteCloudScriptRequest : public PlayFabBaseModel
        {
            AZStd::string FunctionName;
            MultitypeVar FunctionParameter;
            OptionalBool GeneratePlayStreamEvent;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            OptionalInt32 SpecificRevision;

            ExecuteCloudScriptRequest() :
                PlayFabBaseModel(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteCloudScriptRequest(const ExecuteCloudScriptRequest& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ExecuteCloudScriptRequest(const rapidjson::Value& obj) : ExecuteCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("FunctionName");
                writer.String(FunctionName.c_str());
                if (FunctionParameter.notNull()) {
                    writer.String("FunctionParameter");
                    FunctionParameter.writeJSON(writer);
                }
                if (GeneratePlayStreamEvent.notNull()) {
                    writer.String("GeneratePlayStreamEvent");
                    writer.Bool(GeneratePlayStreamEvent);
                }
                if (RevisionSelection.notNull()) {
                    writer.String("RevisionSelection");
                    writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer);
                }
                if (SpecificRevision.notNull()) {
                    writer.String("SpecificRevision");
                    writer.Int(SpecificRevision);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
                if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
                const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
                if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
                const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
                if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();
                const Value::ConstMemberIterator RevisionSelection_member = obj.FindMember("RevisionSelection");
                if (RevisionSelection_member != obj.MemberEnd() && !RevisionSelection_member->value.IsNull()) RevisionSelection = readCloudScriptRevisionOptionFromValue(RevisionSelection_member->value);
                const Value::ConstMemberIterator SpecificRevision_member = obj.FindMember("SpecificRevision");
                if (SpecificRevision_member != obj.MemberEnd() && !SpecificRevision_member->value.IsNull()) SpecificRevision = SpecificRevision_member->value.GetInt();

                return true;
            }
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            AZStd::string Error;
            AZStd::string Message;
            AZStd::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ScriptExecutionError(const rapidjson::Value& obj) : ScriptExecutionError()
            {
                readFromValue(obj);
            }

            ~ScriptExecutionError()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Error.length() > 0) {
                    writer.String("Error");
                    writer.String(Error.c_str());
                }
                if (Message.length() > 0) {
                    writer.String("Message");
                    writer.String(Message.c_str());
                }
                if (StackTrace.length() > 0) {
                    writer.String("StackTrace");
                    writer.String(StackTrace.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
                if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
                const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
                if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
                const Value::ConstMemberIterator StackTrace_member = obj.FindMember("StackTrace");
                if (StackTrace_member != obj.MemberEnd() && !StackTrace_member->value.IsNull()) StackTrace = StackTrace_member->value.GetString();

                return true;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
            MultitypeVar Data;
            AZStd::string Level;
            AZStd::string Message;

            LogStatement() :
                PlayFabBaseModel(),
                Data(),
                Level(),
                Message()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Level(src.Level),
                Message(src.Message)
            {}

            LogStatement(const rapidjson::Value& obj) : LogStatement()
            {
                readFromValue(obj);
            }

            ~LogStatement()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Data.notNull()) {
                    writer.String("Data");
                    Data.writeJSON(writer);
                }
                if (Level.length() > 0) {
                    writer.String("Level");
                    writer.String(Level.c_str());
                }
                if (Message.length() > 0) {
                    writer.String("Message");
                    writer.String(Message.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd() && !Data_member->value.IsNull()) Data = MultitypeVar(Data_member->value);
                const Value::ConstMemberIterator Level_member = obj.FindMember("Level");
                if (Level_member != obj.MemberEnd() && !Level_member->value.IsNull()) Level = Level_member->value.GetString();
                const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
                if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();

                return true;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabBaseModel
        {
            Int32 APIRequestsIssued;
            ScriptExecutionError* Error;
            double ExecutionTimeSeconds;
            AZStd::string FunctionName;
            MultitypeVar FunctionResult;
            OptionalBool FunctionResultTooLarge;
            Int32 HttpRequestsIssued;
            AZStd::vector<LogStatement> Logs; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalBool LogsTooLarge;
            Uint32 MemoryConsumedBytes;
            double ProcessorTimeSeconds;
            Int32 Revision;

            ExecuteCloudScriptResult() :
                PlayFabBaseModel(),
                APIRequestsIssued(0),
                Error(nullptr),
                ExecutionTimeSeconds(0),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge(),
                HttpRequestsIssued(0),
                Logs(),
                LogsTooLarge(),
                MemoryConsumedBytes(0),
                ProcessorTimeSeconds(0),
                Revision(0)
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabBaseModel(),
                APIRequestsIssued(src.APIRequestsIssued),
                Error(src.Error ? new ScriptExecutionError(*src.Error) : nullptr),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                Revision(src.Revision)
            {}

            ExecuteCloudScriptResult(const rapidjson::Value& obj) : ExecuteCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptResult()
            {
                if (Error != nullptr) delete Error;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("APIRequestsIssued");
                writer.Int(APIRequestsIssued);
                if (Error != nullptr) {
                    writer.String("Error");
                    Error->writeJSON(writer);
                }
                writer.String("ExecutionTimeSeconds");
                writer.Double(ExecutionTimeSeconds);
                if (FunctionName.length() > 0) {
                    writer.String("FunctionName");
                    writer.String(FunctionName.c_str());
                }
                if (FunctionResult.notNull()) {
                    writer.String("FunctionResult");
                    FunctionResult.writeJSON(writer);
                }
                if (FunctionResultTooLarge.notNull()) {
                    writer.String("FunctionResultTooLarge");
                    writer.Bool(FunctionResultTooLarge);
                }
                writer.String("HttpRequestsIssued");
                writer.Int(HttpRequestsIssued);
                if (!Logs.empty()) {
                    writer.String("Logs");
                    writer.StartArray();
                    for (auto iter = Logs.begin(); iter != Logs.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (LogsTooLarge.notNull()) {
                    writer.String("LogsTooLarge");
                    writer.Bool(LogsTooLarge);
                }
                writer.String("MemoryConsumedBytes");
                writer.Uint(MemoryConsumedBytes);
                writer.String("ProcessorTimeSeconds");
                writer.Double(ProcessorTimeSeconds);
                writer.String("Revision");
                writer.Int(Revision);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator APIRequestsIssued_member = obj.FindMember("APIRequestsIssued");
                if (APIRequestsIssued_member != obj.MemberEnd() && !APIRequestsIssued_member->value.IsNull()) APIRequestsIssued = APIRequestsIssued_member->value.GetInt();
                const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
                if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = new ScriptExecutionError(Error_member->value);
                const Value::ConstMemberIterator ExecutionTimeSeconds_member = obj.FindMember("ExecutionTimeSeconds");
                if (ExecutionTimeSeconds_member != obj.MemberEnd() && !ExecutionTimeSeconds_member->value.IsNull()) ExecutionTimeSeconds = ExecutionTimeSeconds_member->value.GetDouble();
                const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
                if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
                const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
                if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = MultitypeVar(FunctionResult_member->value);
                const Value::ConstMemberIterator FunctionResultTooLarge_member = obj.FindMember("FunctionResultTooLarge");
                if (FunctionResultTooLarge_member != obj.MemberEnd() && !FunctionResultTooLarge_member->value.IsNull()) FunctionResultTooLarge = FunctionResultTooLarge_member->value.GetBool();
                const Value::ConstMemberIterator HttpRequestsIssued_member = obj.FindMember("HttpRequestsIssued");
                if (HttpRequestsIssued_member != obj.MemberEnd() && !HttpRequestsIssued_member->value.IsNull()) HttpRequestsIssued = HttpRequestsIssued_member->value.GetInt();
                const Value::ConstMemberIterator Logs_member = obj.FindMember("Logs");
                if (Logs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Logs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Logs.push_back(LogStatement(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator LogsTooLarge_member = obj.FindMember("LogsTooLarge");
                if (LogsTooLarge_member != obj.MemberEnd() && !LogsTooLarge_member->value.IsNull()) LogsTooLarge = LogsTooLarge_member->value.GetBool();
                const Value::ConstMemberIterator MemoryConsumedBytes_member = obj.FindMember("MemoryConsumedBytes");
                if (MemoryConsumedBytes_member != obj.MemberEnd() && !MemoryConsumedBytes_member->value.IsNull()) MemoryConsumedBytes = MemoryConsumedBytes_member->value.GetUint();
                const Value::ConstMemberIterator ProcessorTimeSeconds_member = obj.FindMember("ProcessorTimeSeconds");
                if (ProcessorTimeSeconds_member != obj.MemberEnd() && !ProcessorTimeSeconds_member->value.IsNull()) ProcessorTimeSeconds = ProcessorTimeSeconds_member->value.GetDouble();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

                return true;
            }
        };

        struct FacebookPlayFabIdPair : public PlayFabBaseModel
        {
            AZStd::string FacebookId;
            AZStd::string PlayFabId;

            FacebookPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookId(),
                PlayFabId()
            {}

            FacebookPlayFabIdPair(const FacebookPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                PlayFabId(src.PlayFabId)
            {}

            FacebookPlayFabIdPair(const rapidjson::Value& obj) : FacebookPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~FacebookPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (FacebookId.length() > 0) {
                    writer.String("FacebookId");
                    writer.String(FacebookId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
                if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
            AZStd::string FacebookId;
            AZStd::string FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
            {
                readFromValue(obj);
            }

            ~UserFacebookInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (FacebookId.length() > 0) {
                    writer.String("FacebookId");
                    writer.String(FacebookId.c_str());
                }
                if (FullName.length() > 0) {
                    writer.String("FullName");
                    writer.String(FullName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
                if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
                const Value::ConstMemberIterator FullName_member = obj.FindMember("FullName");
                if (FullName_member != obj.MemberEnd() && !FullName_member->value.IsNull()) FullName = FullName_member->value.GetString();

                return true;
            }
        };

        struct UserGameCenterInfo : public PlayFabBaseModel
        {
            AZStd::string GameCenterId;

            UserGameCenterInfo() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            UserGameCenterInfo(const UserGameCenterInfo& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            UserGameCenterInfo(const rapidjson::Value& obj) : UserGameCenterInfo()
            {
                readFromValue(obj);
            }

            ~UserGameCenterInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (GameCenterId.length() > 0) {
                    writer.String("GameCenterId");
                    writer.String(GameCenterId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

                return true;
            }
        };

        enum LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello
        };

        inline void writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case LoginIdentityProviderUnknown: writer.String("Unknown"); break;
            case LoginIdentityProviderPlayFab: writer.String("PlayFab"); break;
            case LoginIdentityProviderCustom: writer.String("Custom"); break;
            case LoginIdentityProviderGameCenter: writer.String("GameCenter"); break;
            case LoginIdentityProviderGooglePlay: writer.String("GooglePlay"); break;
            case LoginIdentityProviderSteam: writer.String("Steam"); break;
            case LoginIdentityProviderXBoxLive: writer.String("XBoxLive"); break;
            case LoginIdentityProviderPSN: writer.String("PSN"); break;
            case LoginIdentityProviderKongregate: writer.String("Kongregate"); break;
            case LoginIdentityProviderFacebook: writer.String("Facebook"); break;
            case LoginIdentityProviderIOSDevice: writer.String("IOSDevice"); break;
            case LoginIdentityProviderAndroidDevice: writer.String("AndroidDevice"); break;
            case LoginIdentityProviderTwitch: writer.String("Twitch"); break;
            case LoginIdentityProviderWindowsHello: writer.String("WindowsHello"); break;

            }
        }

        inline LoginIdentityProvider readLoginIdentityProviderFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<LoginIdentityProvider>(obj.GetInt());

            static std::map<const char *, LoginIdentityProvider, PlayFabClientSdk::StringCompare> _LoginIdentityProviderMap;
            if (_LoginIdentityProviderMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _LoginIdentityProviderMap["Unknown"] = LoginIdentityProviderUnknown;
                _LoginIdentityProviderMap["PlayFab"] = LoginIdentityProviderPlayFab;
                _LoginIdentityProviderMap["Custom"] = LoginIdentityProviderCustom;
                _LoginIdentityProviderMap["GameCenter"] = LoginIdentityProviderGameCenter;
                _LoginIdentityProviderMap["GooglePlay"] = LoginIdentityProviderGooglePlay;
                _LoginIdentityProviderMap["Steam"] = LoginIdentityProviderSteam;
                _LoginIdentityProviderMap["XBoxLive"] = LoginIdentityProviderXBoxLive;
                _LoginIdentityProviderMap["PSN"] = LoginIdentityProviderPSN;
                _LoginIdentityProviderMap["Kongregate"] = LoginIdentityProviderKongregate;
                _LoginIdentityProviderMap["Facebook"] = LoginIdentityProviderFacebook;
                _LoginIdentityProviderMap["IOSDevice"] = LoginIdentityProviderIOSDevice;
                _LoginIdentityProviderMap["AndroidDevice"] = LoginIdentityProviderAndroidDevice;
                _LoginIdentityProviderMap["Twitch"] = LoginIdentityProviderTwitch;
                _LoginIdentityProviderMap["WindowsHello"] = LoginIdentityProviderWindowsHello;

            }

            auto output = _LoginIdentityProviderMap.find(obj.GetString());
            if (output != _LoginIdentityProviderMap.end())
                return output->second;

            return LoginIdentityProviderUnknown; // Basically critical fail
        }

        struct LinkedPlatformAccountModel : public PlayFabBaseModel
        {
            AZStd::string Email;
            Boxed<LoginIdentityProvider> Platform;
            AZStd::string PlatformUserId;
            AZStd::string Username;

            LinkedPlatformAccountModel() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            LinkedPlatformAccountModel(const LinkedPlatformAccountModel& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            LinkedPlatformAccountModel(const rapidjson::Value& obj) : LinkedPlatformAccountModel()
            {
                readFromValue(obj);
            }

            ~LinkedPlatformAccountModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                if (Platform.notNull()) {
                    writer.String("Platform");
                    writeLoginIdentityProviderEnumJSON(Platform, writer);
                }
                if (PlatformUserId.length() > 0) {
                    writer.String("PlatformUserId");
                    writer.String(PlatformUserId.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readLoginIdentityProviderFromValue(Platform_member->value);
                const Value::ConstMemberIterator PlatformUserId_member = obj.FindMember("PlatformUserId");
                if (PlatformUserId_member != obj.MemberEnd() && !PlatformUserId_member->value.IsNull()) PlatformUserId = PlatformUserId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct LocationModel : public PlayFabBaseModel
        {
            AZStd::string City;
            Boxed<ContinentCode> pfContinentCode;
            Boxed<CountryCode> pfCountryCode;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            LocationModel() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            LocationModel(const LocationModel& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            LocationModel(const rapidjson::Value& obj) : LocationModel()
            {
                readFromValue(obj);
            }

            ~LocationModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (City.length() > 0) {
                    writer.String("City");
                    writer.String(City.c_str());
                }
                if (pfContinentCode.notNull()) {
                    writer.String("ContinentCode");
                    writeContinentCodeEnumJSON(pfContinentCode, writer);
                }
                if (pfCountryCode.notNull()) {
                    writer.String("CountryCode");
                    writeCountryCodeEnumJSON(pfCountryCode, writer);
                }
                if (Latitude.notNull()) {
                    writer.String("Latitude");
                    writer.Double(Latitude);
                }
                if (Longitude.notNull()) {
                    writer.String("Longitude");
                    writer.Double(Longitude);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator City_member = obj.FindMember("City");
                if (City_member != obj.MemberEnd() && !City_member->value.IsNull()) City = City_member->value.GetString();
                const Value::ConstMemberIterator ContinentCode_member = obj.FindMember("ContinentCode");
                if (ContinentCode_member != obj.MemberEnd() && !ContinentCode_member->value.IsNull()) pfContinentCode = readContinentCodeFromValue(ContinentCode_member->value);
                const Value::ConstMemberIterator CountryCode_member = obj.FindMember("CountryCode");
                if (CountryCode_member != obj.MemberEnd() && !CountryCode_member->value.IsNull()) pfCountryCode = readCountryCodeFromValue(CountryCode_member->value);
                const Value::ConstMemberIterator Latitude_member = obj.FindMember("Latitude");
                if (Latitude_member != obj.MemberEnd() && !Latitude_member->value.IsNull()) Latitude = Latitude_member->value.GetDouble();
                const Value::ConstMemberIterator Longitude_member = obj.FindMember("Longitude");
                if (Longitude_member != obj.MemberEnd() && !Longitude_member->value.IsNull()) Longitude = Longitude_member->value.GetDouble();

                return true;
            }
        };

        enum SubscriptionProviderStatus
        {
            SubscriptionProviderStatusNoError,
            SubscriptionProviderStatusCancelled,
            SubscriptionProviderStatusUnknownError,
            SubscriptionProviderStatusBillingError,
            SubscriptionProviderStatusProductUnavailable,
            SubscriptionProviderStatusCustomerDidNotAcceptPriceChange,
            SubscriptionProviderStatusFreeTrial,
            SubscriptionProviderStatusPaymentPending
        };

        inline void writeSubscriptionProviderStatusEnumJSON(SubscriptionProviderStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case SubscriptionProviderStatusNoError: writer.String("NoError"); break;
            case SubscriptionProviderStatusCancelled: writer.String("Cancelled"); break;
            case SubscriptionProviderStatusUnknownError: writer.String("UnknownError"); break;
            case SubscriptionProviderStatusBillingError: writer.String("BillingError"); break;
            case SubscriptionProviderStatusProductUnavailable: writer.String("ProductUnavailable"); break;
            case SubscriptionProviderStatusCustomerDidNotAcceptPriceChange: writer.String("CustomerDidNotAcceptPriceChange"); break;
            case SubscriptionProviderStatusFreeTrial: writer.String("FreeTrial"); break;
            case SubscriptionProviderStatusPaymentPending: writer.String("PaymentPending"); break;

            }
        }

        inline SubscriptionProviderStatus readSubscriptionProviderStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<SubscriptionProviderStatus>(obj.GetInt());

            static std::map<const char *, SubscriptionProviderStatus, PlayFabClientSdk::StringCompare> _SubscriptionProviderStatusMap;
            if (_SubscriptionProviderStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _SubscriptionProviderStatusMap["NoError"] = SubscriptionProviderStatusNoError;
                _SubscriptionProviderStatusMap["Cancelled"] = SubscriptionProviderStatusCancelled;
                _SubscriptionProviderStatusMap["UnknownError"] = SubscriptionProviderStatusUnknownError;
                _SubscriptionProviderStatusMap["BillingError"] = SubscriptionProviderStatusBillingError;
                _SubscriptionProviderStatusMap["ProductUnavailable"] = SubscriptionProviderStatusProductUnavailable;
                _SubscriptionProviderStatusMap["CustomerDidNotAcceptPriceChange"] = SubscriptionProviderStatusCustomerDidNotAcceptPriceChange;
                _SubscriptionProviderStatusMap["FreeTrial"] = SubscriptionProviderStatusFreeTrial;
                _SubscriptionProviderStatusMap["PaymentPending"] = SubscriptionProviderStatusPaymentPending;

            }

            auto output = _SubscriptionProviderStatusMap.find(obj.GetString());
            if (output != _SubscriptionProviderStatusMap.end())
                return output->second;

            return SubscriptionProviderStatusNoError; // Basically critical fail
        }

        struct SubscriptionModel : public PlayFabBaseModel
        {
            time_t Expiration;
            time_t InitialSubscriptionTime;
            bool IsActive;
            Boxed<SubscriptionProviderStatus> Status;
            AZStd::string SubscriptionId;
            AZStd::string SubscriptionItemId;
            AZStd::string SubscriptionProvider;

            SubscriptionModel() :
                PlayFabBaseModel(),
                Expiration(0),
                InitialSubscriptionTime(0),
                IsActive(false),
                Status(),
                SubscriptionId(),
                SubscriptionItemId(),
                SubscriptionProvider()
            {}

            SubscriptionModel(const SubscriptionModel& src) :
                PlayFabBaseModel(),
                Expiration(src.Expiration),
                InitialSubscriptionTime(src.InitialSubscriptionTime),
                IsActive(src.IsActive),
                Status(src.Status),
                SubscriptionId(src.SubscriptionId),
                SubscriptionItemId(src.SubscriptionItemId),
                SubscriptionProvider(src.SubscriptionProvider)
            {}

            SubscriptionModel(const rapidjson::Value& obj) : SubscriptionModel()
            {
                readFromValue(obj);
            }

            ~SubscriptionModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Expiration");
                writeDatetime(Expiration, writer);
                writer.String("InitialSubscriptionTime");
                writeDatetime(InitialSubscriptionTime, writer);
                writer.String("IsActive");
                writer.Bool(IsActive);
                if (Status.notNull()) {
                    writer.String("Status");
                    writeSubscriptionProviderStatusEnumJSON(Status, writer);
                }
                if (SubscriptionId.length() > 0) {
                    writer.String("SubscriptionId");
                    writer.String(SubscriptionId.c_str());
                }
                if (SubscriptionItemId.length() > 0) {
                    writer.String("SubscriptionItemId");
                    writer.String(SubscriptionItemId.c_str());
                }
                if (SubscriptionProvider.length() > 0) {
                    writer.String("SubscriptionProvider");
                    writer.String(SubscriptionProvider.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
                if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
                const Value::ConstMemberIterator InitialSubscriptionTime_member = obj.FindMember("InitialSubscriptionTime");
                if (InitialSubscriptionTime_member != obj.MemberEnd() && !InitialSubscriptionTime_member->value.IsNull()) InitialSubscriptionTime = readDatetime(InitialSubscriptionTime_member->value);
                const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
                if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readSubscriptionProviderStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator SubscriptionId_member = obj.FindMember("SubscriptionId");
                if (SubscriptionId_member != obj.MemberEnd() && !SubscriptionId_member->value.IsNull()) SubscriptionId = SubscriptionId_member->value.GetString();
                const Value::ConstMemberIterator SubscriptionItemId_member = obj.FindMember("SubscriptionItemId");
                if (SubscriptionItemId_member != obj.MemberEnd() && !SubscriptionItemId_member->value.IsNull()) SubscriptionItemId = SubscriptionItemId_member->value.GetString();
                const Value::ConstMemberIterator SubscriptionProvider_member = obj.FindMember("SubscriptionProvider");
                if (SubscriptionProvider_member != obj.MemberEnd() && !SubscriptionProvider_member->value.IsNull()) SubscriptionProvider = SubscriptionProvider_member->value.GetString();

                return true;
            }
        };

        struct MembershipModel : public PlayFabBaseModel
        {
            bool IsActive;
            time_t MembershipExpiration;
            AZStd::string MembershipId;
            OptionalTime OverrideExpiration;
            AZStd::vector<SubscriptionModel> Subscriptions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            MembershipModel() :
                PlayFabBaseModel(),
                IsActive(false),
                MembershipExpiration(0),
                MembershipId(),
                OverrideExpiration(),
                Subscriptions()
            {}

            MembershipModel(const MembershipModel& src) :
                PlayFabBaseModel(),
                IsActive(src.IsActive),
                MembershipExpiration(src.MembershipExpiration),
                MembershipId(src.MembershipId),
                OverrideExpiration(src.OverrideExpiration),
                Subscriptions(src.Subscriptions)
            {}

            MembershipModel(const rapidjson::Value& obj) : MembershipModel()
            {
                readFromValue(obj);
            }

            ~MembershipModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("IsActive");
                writer.Bool(IsActive);
                writer.String("MembershipExpiration");
                writeDatetime(MembershipExpiration, writer);
                if (MembershipId.length() > 0) {
                    writer.String("MembershipId");
                    writer.String(MembershipId.c_str());
                }
                if (OverrideExpiration.notNull()) {
                    writer.String("OverrideExpiration");
                    writeDatetime(OverrideExpiration, writer);
                }
                if (!Subscriptions.empty()) {
                    writer.String("Subscriptions");
                    writer.StartArray();
                    for (auto iter = Subscriptions.begin(); iter != Subscriptions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
                if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
                const Value::ConstMemberIterator MembershipExpiration_member = obj.FindMember("MembershipExpiration");
                if (MembershipExpiration_member != obj.MemberEnd() && !MembershipExpiration_member->value.IsNull()) MembershipExpiration = readDatetime(MembershipExpiration_member->value);
                const Value::ConstMemberIterator MembershipId_member = obj.FindMember("MembershipId");
                if (MembershipId_member != obj.MemberEnd() && !MembershipId_member->value.IsNull()) MembershipId = MembershipId_member->value.GetString();
                const Value::ConstMemberIterator OverrideExpiration_member = obj.FindMember("OverrideExpiration");
                if (OverrideExpiration_member != obj.MemberEnd() && !OverrideExpiration_member->value.IsNull()) OverrideExpiration = readDatetime(OverrideExpiration_member->value);
                const Value::ConstMemberIterator Subscriptions_member = obj.FindMember("Subscriptions");
                if (Subscriptions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Subscriptions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Subscriptions.push_back(SubscriptionModel(memberList[i]));
                    }
                }

                return true;
            }
        };

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        inline void writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case PushNotificationPlatformApplePushNotificationService: writer.String("ApplePushNotificationService"); break;
            case PushNotificationPlatformGoogleCloudMessaging: writer.String("GoogleCloudMessaging"); break;

            }
        }

        inline PushNotificationPlatform readPushNotificationPlatformFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<PushNotificationPlatform>(obj.GetInt());

            static std::map<const char *, PushNotificationPlatform, PlayFabClientSdk::StringCompare> _PushNotificationPlatformMap;
            if (_PushNotificationPlatformMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _PushNotificationPlatformMap["ApplePushNotificationService"] = PushNotificationPlatformApplePushNotificationService;
                _PushNotificationPlatformMap["GoogleCloudMessaging"] = PushNotificationPlatformGoogleCloudMessaging;

            }

            auto output = _PushNotificationPlatformMap.find(obj.GetString());
            if (output != _PushNotificationPlatformMap.end())
                return output->second;

            return PushNotificationPlatformApplePushNotificationService; // Basically critical fail
        }

        struct PushNotificationRegistrationModel : public PlayFabBaseModel
        {
            AZStd::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistrationModel() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistrationModel(const PushNotificationRegistrationModel& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            PushNotificationRegistrationModel(const rapidjson::Value& obj) : PushNotificationRegistrationModel()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistrationModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (NotificationEndpointARN.length() > 0) {
                    writer.String("NotificationEndpointARN");
                    writer.String(NotificationEndpointARN.c_str());
                }
                if (Platform.notNull()) {
                    writer.String("Platform");
                    writePushNotificationPlatformEnumJSON(Platform, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator NotificationEndpointARN_member = obj.FindMember("NotificationEndpointARN");
                if (NotificationEndpointARN_member != obj.MemberEnd() && !NotificationEndpointARN_member->value.IsNull()) NotificationEndpointARN = NotificationEndpointARN_member->value.GetString();
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);

                return true;
            }
        };

        struct StatisticModel : public PlayFabBaseModel
        {
            AZStd::string Name;
            Int32 Value;
            Int32 Version;

            StatisticModel() :
                PlayFabBaseModel(),
                Name(),
                Value(0),
                Version(0)
            {}

            StatisticModel(const StatisticModel& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticModel(const rapidjson::Value& obj) : StatisticModel()
            {
                readFromValue(obj);
            }

            ~StatisticModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                writer.String("Value");
                writer.Int(Value);
                writer.String("Version");
                writer.Int(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct TagModel : public PlayFabBaseModel
        {
            AZStd::string TagValue;

            TagModel() :
                PlayFabBaseModel(),
                TagValue()
            {}

            TagModel(const TagModel& src) :
                PlayFabBaseModel(),
                TagValue(src.TagValue)
            {}

            TagModel(const rapidjson::Value& obj) : TagModel()
            {
                readFromValue(obj);
            }

            ~TagModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (TagValue.length() > 0) {
                    writer.String("TagValue");
                    writer.String(TagValue.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TagValue_member = obj.FindMember("TagValue");
                if (TagValue_member != obj.MemberEnd() && !TagValue_member->value.IsNull()) TagValue = TagValue_member->value.GetString();

                return true;
            }
        };

        struct ValueToDateModel : public PlayFabBaseModel
        {
            AZStd::string Currency;
            Uint32 TotalValue;
            AZStd::string TotalValueAsDecimal;

            ValueToDateModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0),
                TotalValueAsDecimal()
            {}

            ValueToDateModel(const ValueToDateModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue),
                TotalValueAsDecimal(src.TotalValueAsDecimal)
            {}

            ValueToDateModel(const rapidjson::Value& obj) : ValueToDateModel()
            {
                readFromValue(obj);
            }

            ~ValueToDateModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Currency.length() > 0) {
                    writer.String("Currency");
                    writer.String(Currency.c_str());
                }
                writer.String("TotalValue");
                writer.Uint(TotalValue);
                if (TotalValueAsDecimal.length() > 0) {
                    writer.String("TotalValueAsDecimal");
                    writer.String(TotalValueAsDecimal.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator TotalValue_member = obj.FindMember("TotalValue");
                if (TotalValue_member != obj.MemberEnd() && !TotalValue_member->value.IsNull()) TotalValue = TotalValue_member->value.GetUint();
                const Value::ConstMemberIterator TotalValueAsDecimal_member = obj.FindMember("TotalValueAsDecimal");
                if (TotalValueAsDecimal_member != obj.MemberEnd() && !TotalValueAsDecimal_member->value.IsNull()) TotalValueAsDecimal = TotalValueAsDecimal_member->value.GetString();

                return true;
            }
        };

        struct PlayerProfileModel : public PlayFabBaseModel
        {
            AZStd::vector<AdCampaignAttributionModel> AdCampaignAttributions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string AvatarUrl;
            OptionalTime BannedUntil;
            AZStd::vector<ContactEmailInfoModel> ContactEmailAddresses; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalTime Created;
            AZStd::string DisplayName;
            OptionalTime LastLogin;
            AZStd::vector<LinkedPlatformAccountModel> LinkedAccounts; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<LocationModel> Locations; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<MembershipModel> Memberships; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<LoginIdentityProvider> Origination;
            AZStd::string PlayerId;
            AZStd::string PublisherId;
            AZStd::vector<PushNotificationRegistrationModel> PushNotificationRegistrations; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<StatisticModel> Statistics; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<TagModel> Tags; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string TitleId;
            OptionalUint32 TotalValueToDateInUSD;
            AZStd::vector<ValueToDateModel> ValuesToDate; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            PlayerProfileModel() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Memberships(),
                Origination(),
                PlayerId(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate()
            {}

            PlayerProfileModel(const PlayerProfileModel& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Memberships(src.Memberships),
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate)
            {}

            PlayerProfileModel(const rapidjson::Value& obj) : PlayerProfileModel()
            {
                readFromValue(obj);
            }

            ~PlayerProfileModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!AdCampaignAttributions.empty()) {
                    writer.String("AdCampaignAttributions");
                    writer.StartArray();
                    for (auto iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (AvatarUrl.length() > 0) {
                    writer.String("AvatarUrl");
                    writer.String(AvatarUrl.c_str());
                }
                if (BannedUntil.notNull()) {
                    writer.String("BannedUntil");
                    writeDatetime(BannedUntil, writer);
                }
                if (!ContactEmailAddresses.empty()) {
                    writer.String("ContactEmailAddresses");
                    writer.StartArray();
                    for (auto iter = ContactEmailAddresses.begin(); iter != ContactEmailAddresses.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (Created.notNull()) {
                    writer.String("Created");
                    writeDatetime(Created, writer);
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (LastLogin.notNull()) {
                    writer.String("LastLogin");
                    writeDatetime(LastLogin, writer);
                }
                if (!LinkedAccounts.empty()) {
                    writer.String("LinkedAccounts");
                    writer.StartArray();
                    for (auto iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Locations.empty()) {
                    writer.String("Locations");
                    writer.StartArray();
                    for (auto iter = Locations.begin(); iter != Locations.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Memberships.empty()) {
                    writer.String("Memberships");
                    writer.StartArray();
                    for (auto iter = Memberships.begin(); iter != Memberships.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (Origination.notNull()) {
                    writer.String("Origination");
                    writeLoginIdentityProviderEnumJSON(Origination, writer);
                }
                if (PlayerId.length() > 0) {
                    writer.String("PlayerId");
                    writer.String(PlayerId.c_str());
                }
                if (PublisherId.length() > 0) {
                    writer.String("PublisherId");
                    writer.String(PublisherId.c_str());
                }
                if (!PushNotificationRegistrations.empty()) {
                    writer.String("PushNotificationRegistrations");
                    writer.StartArray();
                    for (auto iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Statistics.empty()) {
                    writer.String("Statistics");
                    writer.StartArray();
                    for (auto iter = Statistics.begin(); iter != Statistics.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (auto iter = Tags.begin(); iter != Tags.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                if (TotalValueToDateInUSD.notNull()) {
                    writer.String("TotalValueToDateInUSD");
                    writer.Uint(TotalValueToDateInUSD);
                }
                if (!ValuesToDate.empty()) {
                    writer.String("ValuesToDate");
                    writer.StartArray();
                    for (auto iter = ValuesToDate.begin(); iter != ValuesToDate.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
                if (AdCampaignAttributions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AdCampaignAttributions.push_back(AdCampaignAttributionModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
                const Value::ConstMemberIterator BannedUntil_member = obj.FindMember("BannedUntil");
                if (BannedUntil_member != obj.MemberEnd() && !BannedUntil_member->value.IsNull()) BannedUntil = readDatetime(BannedUntil_member->value);
                const Value::ConstMemberIterator ContactEmailAddresses_member = obj.FindMember("ContactEmailAddresses");
                if (ContactEmailAddresses_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ContactEmailAddresses_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ContactEmailAddresses.push_back(ContactEmailInfoModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
                if (LinkedAccounts_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = LinkedAccounts_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        LinkedAccounts.push_back(LinkedPlatformAccountModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Locations_member = obj.FindMember("Locations");
                if (Locations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Locations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Locations.push_back(LocationModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Memberships_member = obj.FindMember("Memberships");
                if (Memberships_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Memberships_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Memberships.push_back(MembershipModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
                const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
                if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
                const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
                if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
                const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
                if (PushNotificationRegistrations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PushNotificationRegistrations.push_back(PushNotificationRegistrationModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
                if (Statistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statistics.push_back(StatisticModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(TagModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
                if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
                const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
                if (ValuesToDate_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ValuesToDate_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ValuesToDate.push_back(ValueToDateModel(memberList[i]));
                    }
                }

                return true;
            }
        };

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        inline void writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TitleActivationStatusNone: writer.String("None"); break;
            case TitleActivationStatusActivatedTitleKey: writer.String("ActivatedTitleKey"); break;
            case TitleActivationStatusPendingSteam: writer.String("PendingSteam"); break;
            case TitleActivationStatusActivatedSteam: writer.String("ActivatedSteam"); break;
            case TitleActivationStatusRevokedSteam: writer.String("RevokedSteam"); break;

            }
        }

        inline TitleActivationStatus readTitleActivationStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<TitleActivationStatus>(obj.GetInt());

            static std::map<const char *, TitleActivationStatus, PlayFabClientSdk::StringCompare> _TitleActivationStatusMap;
            if (_TitleActivationStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TitleActivationStatusMap["None"] = TitleActivationStatusNone;
                _TitleActivationStatusMap["ActivatedTitleKey"] = TitleActivationStatusActivatedTitleKey;
                _TitleActivationStatusMap["PendingSteam"] = TitleActivationStatusPendingSteam;
                _TitleActivationStatusMap["ActivatedSteam"] = TitleActivationStatusActivatedSteam;
                _TitleActivationStatusMap["RevokedSteam"] = TitleActivationStatusRevokedSteam;

            }

            auto output = _TitleActivationStatusMap.find(obj.GetString());
            if (output != _TitleActivationStatusMap.end())
                return output->second;

            return TitleActivationStatusNone; // Basically critical fail
        }

        struct UserSteamInfo : public PlayFabBaseModel
        {
            Boxed<TitleActivationStatus> SteamActivationStatus;
            AZStd::string SteamCountry;
            Boxed<Currency> SteamCurrency;
            AZStd::string SteamId;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamActivationStatus(),
                SteamCountry(),
                SteamCurrency(),
                SteamId()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamActivationStatus(src.SteamActivationStatus),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamId(src.SteamId)
            {}

            UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
            {
                readFromValue(obj);
            }

            ~UserSteamInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (SteamActivationStatus.notNull()) {
                    writer.String("SteamActivationStatus");
                    writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer);
                }
                if (SteamCountry.length() > 0) {
                    writer.String("SteamCountry");
                    writer.String(SteamCountry.c_str());
                }
                if (SteamCurrency.notNull()) {
                    writer.String("SteamCurrency");
                    writeCurrencyEnumJSON(SteamCurrency, writer);
                }
                if (SteamId.length() > 0) {
                    writer.String("SteamId");
                    writer.String(SteamId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
                if (SteamActivationStatus_member != obj.MemberEnd() && !SteamActivationStatus_member->value.IsNull()) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);
                const Value::ConstMemberIterator SteamCountry_member = obj.FindMember("SteamCountry");
                if (SteamCountry_member != obj.MemberEnd() && !SteamCountry_member->value.IsNull()) SteamCountry = SteamCountry_member->value.GetString();
                const Value::ConstMemberIterator SteamCurrency_member = obj.FindMember("SteamCurrency");
                if (SteamCurrency_member != obj.MemberEnd() && !SteamCurrency_member->value.IsNull()) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
                const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
                if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();

                return true;
            }
        };

        struct FriendInfo : public PlayFabBaseModel
        {
            AZStd::string CurrentMatchmakerLobbyId;
            UserFacebookInfo* FacebookInfo;
            AZStd::string FriendPlayFabId;
            UserGameCenterInfo* GameCenterInfo;
            PlayerProfileModel* Profile;
            UserSteamInfo* SteamInfo;
            AZStd::vector<AZStd::string> Tags; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string TitleDisplayName;
            AZStd::string Username;

            FriendInfo() :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(),
                FacebookInfo(nullptr),
                FriendPlayFabId(),
                GameCenterInfo(nullptr),
                Profile(nullptr),
                SteamInfo(nullptr),
                Tags(),
                TitleDisplayName(),
                Username()
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(src.CurrentMatchmakerLobbyId),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : nullptr),
                FriendPlayFabId(src.FriendPlayFabId),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : nullptr),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : nullptr),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : nullptr),
                Tags(src.Tags),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            FriendInfo(const rapidjson::Value& obj) : FriendInfo()
            {
                readFromValue(obj);
            }

            ~FriendInfo()
            {
                if (FacebookInfo != nullptr) delete FacebookInfo;
                if (GameCenterInfo != nullptr) delete GameCenterInfo;
                if (Profile != nullptr) delete Profile;
                if (SteamInfo != nullptr) delete SteamInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CurrentMatchmakerLobbyId.length() > 0) {
                    writer.String("CurrentMatchmakerLobbyId");
                    writer.String(CurrentMatchmakerLobbyId.c_str());
                }
                if (FacebookInfo != nullptr) {
                    writer.String("FacebookInfo");
                    FacebookInfo->writeJSON(writer);
                }
                if (FriendPlayFabId.length() > 0) {
                    writer.String("FriendPlayFabId");
                    writer.String(FriendPlayFabId.c_str());
                }
                if (GameCenterInfo != nullptr) {
                    writer.String("GameCenterInfo");
                    GameCenterInfo->writeJSON(writer);
                }
                if (Profile != nullptr) {
                    writer.String("Profile");
                    Profile->writeJSON(writer);
                }
                if (SteamInfo != nullptr) {
                    writer.String("SteamInfo");
                    SteamInfo->writeJSON(writer);
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (auto iter = Tags.begin(); iter != Tags.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (TitleDisplayName.length() > 0) {
                    writer.String("TitleDisplayName");
                    writer.String(TitleDisplayName.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CurrentMatchmakerLobbyId_member = obj.FindMember("CurrentMatchmakerLobbyId");
                if (CurrentMatchmakerLobbyId_member != obj.MemberEnd() && !CurrentMatchmakerLobbyId_member->value.IsNull()) CurrentMatchmakerLobbyId = CurrentMatchmakerLobbyId_member->value.GetString();
                const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
                if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
                if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
                const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
                if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new PlayerProfileModel(Profile_member->value);
                const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
                if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
                if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct GameCenterPlayFabIdPair : public PlayFabBaseModel
        {
            AZStd::string GameCenterId;
            AZStd::string PlayFabId;

            GameCenterPlayFabIdPair() :
                PlayFabBaseModel(),
                GameCenterId(),
                PlayFabId()
            {}

            GameCenterPlayFabIdPair(const GameCenterPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId),
                PlayFabId(src.PlayFabId)
            {}

            GameCenterPlayFabIdPair(const rapidjson::Value& obj) : GameCenterPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GameCenterPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (GameCenterId.length() > 0) {
                    writer.String("GameCenterId");
                    writer.String(GameCenterId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GameServerRegionsRequest : public PlayFabBaseModel
        {
            AZStd::string BuildVersion;
            AZStd::string TitleId;

            GameServerRegionsRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                TitleId()
            {}

            GameServerRegionsRequest(const GameServerRegionsRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                TitleId(src.TitleId)
            {}

            GameServerRegionsRequest(const rapidjson::Value& obj) : GameServerRegionsRequest()
            {
                readFromValue(obj);
            }

            ~GameServerRegionsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("BuildVersion");
                writer.String(BuildVersion.c_str());
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct RegionInfo : public PlayFabBaseModel
        {
            bool Available;
            AZStd::string Name;
            AZStd::string PingUrl;
            Boxed<Region> pfRegion;

            RegionInfo() :
                PlayFabBaseModel(),
                Available(false),
                Name(),
                PingUrl(),
                pfRegion()
            {}

            RegionInfo(const RegionInfo& src) :
                PlayFabBaseModel(),
                Available(src.Available),
                Name(src.Name),
                PingUrl(src.PingUrl),
                pfRegion(src.pfRegion)
            {}

            RegionInfo(const rapidjson::Value& obj) : RegionInfo()
            {
                readFromValue(obj);
            }

            ~RegionInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Available");
                writer.Bool(Available);
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                if (PingUrl.length() > 0) {
                    writer.String("PingUrl");
                    writer.String(PingUrl.c_str());
                }
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Available_member = obj.FindMember("Available");
                if (Available_member != obj.MemberEnd() && !Available_member->value.IsNull()) Available = Available_member->value.GetBool();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator PingUrl_member = obj.FindMember("PingUrl");
                if (PingUrl_member != obj.MemberEnd() && !PingUrl_member->value.IsNull()) PingUrl = PingUrl_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);

                return true;
            }
        };

        struct GameServerRegionsResult : public PlayFabBaseModel
        {
            AZStd::vector<RegionInfo> Regions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GameServerRegionsResult() :
                PlayFabBaseModel(),
                Regions()
            {}

            GameServerRegionsResult(const GameServerRegionsResult& src) :
                PlayFabBaseModel(),
                Regions(src.Regions)
            {}

            GameServerRegionsResult(const rapidjson::Value& obj) : GameServerRegionsResult()
            {
                readFromValue(obj);
            }

            ~GameServerRegionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Regions.empty()) {
                    writer.String("Regions");
                    writer.StartArray();
                    for (auto iter = Regions.begin(); iter != Regions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Regions_member = obj.FindMember("Regions");
                if (Regions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Regions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Regions.push_back(RegionInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GenericPlayFabIdPair : public PlayFabBaseModel
        {
            GenericServiceId* GenericId;
            AZStd::string PlayFabId;

            GenericPlayFabIdPair() :
                PlayFabBaseModel(),
                GenericId(nullptr),
                PlayFabId()
            {}

            GenericPlayFabIdPair(const GenericPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId ? new GenericServiceId(*src.GenericId) : nullptr),
                PlayFabId(src.PlayFabId)
            {}

            GenericPlayFabIdPair(const rapidjson::Value& obj) : GenericPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GenericPlayFabIdPair()
            {
                if (GenericId != nullptr) delete GenericId;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (GenericId != nullptr) {
                    writer.String("GenericId");
                    GenericId->writeJSON(writer);
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericId_member = obj.FindMember("GenericId");
                if (GenericId_member != obj.MemberEnd() && !GenericId_member->value.IsNull()) GenericId = new GenericServiceId(GenericId_member->value);
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetAccountInfoRequest : public PlayFabBaseModel
        {
            AZStd::string Email;
            AZStd::string PlayFabId;
            AZStd::string TitleDisplayName;
            AZStd::string Username;

            GetAccountInfoRequest() :
                PlayFabBaseModel(),
                Email(),
                PlayFabId(),
                TitleDisplayName(),
                Username()
            {}

            GetAccountInfoRequest(const GetAccountInfoRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                PlayFabId(src.PlayFabId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            GetAccountInfoRequest(const rapidjson::Value& obj) : GetAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetAccountInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (TitleDisplayName.length() > 0) {
                    writer.String("TitleDisplayName");
                    writer.String(TitleDisplayName.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
                if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
            AZStd::string AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UserAndroidDeviceInfo(const rapidjson::Value& obj) : UserAndroidDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserAndroidDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AndroidDeviceId.length() > 0) {
                    writer.String("AndroidDeviceId");
                    writer.String(AndroidDeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
            AZStd::string CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UserCustomIdInfo(const rapidjson::Value& obj) : UserCustomIdInfo()
            {
                readFromValue(obj);
            }

            ~UserCustomIdInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CustomId.length() > 0) {
                    writer.String("CustomId");
                    writer.String(CustomId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

                return true;
            }
        };

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            AZStd::string GoogleEmail;
            AZStd::string GoogleGender;
            AZStd::string GoogleId;
            AZStd::string GoogleLocale;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleEmail(),
                GoogleGender(),
                GoogleId(),
                GoogleLocale()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleEmail(src.GoogleEmail),
                GoogleGender(src.GoogleGender),
                GoogleId(src.GoogleId),
                GoogleLocale(src.GoogleLocale)
            {}

            UserGoogleInfo(const rapidjson::Value& obj) : UserGoogleInfo()
            {
                readFromValue(obj);
            }

            ~UserGoogleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (GoogleEmail.length() > 0) {
                    writer.String("GoogleEmail");
                    writer.String(GoogleEmail.c_str());
                }
                if (GoogleGender.length() > 0) {
                    writer.String("GoogleGender");
                    writer.String(GoogleGender.c_str());
                }
                if (GoogleId.length() > 0) {
                    writer.String("GoogleId");
                    writer.String(GoogleId.c_str());
                }
                if (GoogleLocale.length() > 0) {
                    writer.String("GoogleLocale");
                    writer.String(GoogleLocale.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleEmail_member = obj.FindMember("GoogleEmail");
                if (GoogleEmail_member != obj.MemberEnd() && !GoogleEmail_member->value.IsNull()) GoogleEmail = GoogleEmail_member->value.GetString();
                const Value::ConstMemberIterator GoogleGender_member = obj.FindMember("GoogleGender");
                if (GoogleGender_member != obj.MemberEnd() && !GoogleGender_member->value.IsNull()) GoogleGender = GoogleGender_member->value.GetString();
                const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
                if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
                const Value::ConstMemberIterator GoogleLocale_member = obj.FindMember("GoogleLocale");
                if (GoogleLocale_member != obj.MemberEnd() && !GoogleLocale_member->value.IsNull()) GoogleLocale = GoogleLocale_member->value.GetString();

                return true;
            }
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
            AZStd::string IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            UserIosDeviceInfo(const rapidjson::Value& obj) : UserIosDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserIosDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (IosDeviceId.length() > 0) {
                    writer.String("IosDeviceId");
                    writer.String(IosDeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IosDeviceId_member = obj.FindMember("IosDeviceId");
                if (IosDeviceId_member != obj.MemberEnd() && !IosDeviceId_member->value.IsNull()) IosDeviceId = IosDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
            AZStd::string KongregateId;
            AZStd::string KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            UserKongregateInfo(const rapidjson::Value& obj) : UserKongregateInfo()
            {
                readFromValue(obj);
            }

            ~UserKongregateInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (KongregateId.length() > 0) {
                    writer.String("KongregateId");
                    writer.String(KongregateId.c_str());
                }
                if (KongregateName.length() > 0) {
                    writer.String("KongregateName");
                    writer.String(KongregateName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator KongregateName_member = obj.FindMember("KongregateName");
                if (KongregateName_member != obj.MemberEnd() && !KongregateName_member->value.IsNull()) KongregateName = KongregateName_member->value.GetString();

                return true;
            }
        };

        struct UserPrivateAccountInfo : public PlayFabBaseModel
        {
            AZStd::string Email;

            UserPrivateAccountInfo() :
                PlayFabBaseModel(),
                Email()
            {}

            UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            UserPrivateAccountInfo(const rapidjson::Value& obj) : UserPrivateAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserPrivateAccountInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct UserPsnInfo : public PlayFabBaseModel
        {
            AZStd::string PsnAccountId;
            AZStd::string PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            UserPsnInfo(const rapidjson::Value& obj) : UserPsnInfo()
            {
                readFromValue(obj);
            }

            ~UserPsnInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (PsnAccountId.length() > 0) {
                    writer.String("PsnAccountId");
                    writer.String(PsnAccountId.c_str());
                }
                if (PsnOnlineId.length() > 0) {
                    writer.String("PsnOnlineId");
                    writer.String(PsnOnlineId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PsnAccountId_member = obj.FindMember("PsnAccountId");
                if (PsnAccountId_member != obj.MemberEnd() && !PsnAccountId_member->value.IsNull()) PsnAccountId = PsnAccountId_member->value.GetString();
                const Value::ConstMemberIterator PsnOnlineId_member = obj.FindMember("PsnOnlineId");
                if (PsnOnlineId_member != obj.MemberEnd() && !PsnOnlineId_member->value.IsNull()) PsnOnlineId = PsnOnlineId_member->value.GetString();

                return true;
            }
        };

        enum UserOrigination
        {
            UserOriginationOrganic,
            UserOriginationSteam,
            UserOriginationGoogle,
            UserOriginationAmazon,
            UserOriginationFacebook,
            UserOriginationKongregate,
            UserOriginationGamersFirst,
            UserOriginationUnknown,
            UserOriginationIOS,
            UserOriginationLoadTest,
            UserOriginationAndroid,
            UserOriginationPSN,
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive,
            UserOriginationParse,
            UserOriginationTwitch,
            UserOriginationWindowsHello
        };

        inline void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserOriginationOrganic: writer.String("Organic"); break;
            case UserOriginationSteam: writer.String("Steam"); break;
            case UserOriginationGoogle: writer.String("Google"); break;
            case UserOriginationAmazon: writer.String("Amazon"); break;
            case UserOriginationFacebook: writer.String("Facebook"); break;
            case UserOriginationKongregate: writer.String("Kongregate"); break;
            case UserOriginationGamersFirst: writer.String("GamersFirst"); break;
            case UserOriginationUnknown: writer.String("Unknown"); break;
            case UserOriginationIOS: writer.String("IOS"); break;
            case UserOriginationLoadTest: writer.String("LoadTest"); break;
            case UserOriginationAndroid: writer.String("Android"); break;
            case UserOriginationPSN: writer.String("PSN"); break;
            case UserOriginationGameCenter: writer.String("GameCenter"); break;
            case UserOriginationCustomId: writer.String("CustomId"); break;
            case UserOriginationXboxLive: writer.String("XboxLive"); break;
            case UserOriginationParse: writer.String("Parse"); break;
            case UserOriginationTwitch: writer.String("Twitch"); break;
            case UserOriginationWindowsHello: writer.String("WindowsHello"); break;

            }
        }

        inline UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<UserOrigination>(obj.GetInt());

            static std::map<const char *, UserOrigination, PlayFabClientSdk::StringCompare> _UserOriginationMap;
            if (_UserOriginationMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserOriginationMap["Organic"] = UserOriginationOrganic;
                _UserOriginationMap["Steam"] = UserOriginationSteam;
                _UserOriginationMap["Google"] = UserOriginationGoogle;
                _UserOriginationMap["Amazon"] = UserOriginationAmazon;
                _UserOriginationMap["Facebook"] = UserOriginationFacebook;
                _UserOriginationMap["Kongregate"] = UserOriginationKongregate;
                _UserOriginationMap["GamersFirst"] = UserOriginationGamersFirst;
                _UserOriginationMap["Unknown"] = UserOriginationUnknown;
                _UserOriginationMap["IOS"] = UserOriginationIOS;
                _UserOriginationMap["LoadTest"] = UserOriginationLoadTest;
                _UserOriginationMap["Android"] = UserOriginationAndroid;
                _UserOriginationMap["PSN"] = UserOriginationPSN;
                _UserOriginationMap["GameCenter"] = UserOriginationGameCenter;
                _UserOriginationMap["CustomId"] = UserOriginationCustomId;
                _UserOriginationMap["XboxLive"] = UserOriginationXboxLive;
                _UserOriginationMap["Parse"] = UserOriginationParse;
                _UserOriginationMap["Twitch"] = UserOriginationTwitch;
                _UserOriginationMap["WindowsHello"] = UserOriginationWindowsHello;

            }

            auto output = _UserOriginationMap.find(obj.GetString());
            if (output != _UserOriginationMap.end())
                return output->second;

            return UserOriginationOrganic; // Basically critical fail
        }

        struct UserTitleInfo : public PlayFabBaseModel
        {
            AZStd::string AvatarUrl;
            time_t Created;
            AZStd::string DisplayName;
            OptionalTime FirstLogin;
            OptionalBool isBanned;
            OptionalTime LastLogin;
            Boxed<UserOrigination> Origination;
            EntityKey* TitlePlayerAccount;

            UserTitleInfo() :
                PlayFabBaseModel(),
                AvatarUrl(),
                Created(0),
                DisplayName(),
                FirstLogin(),
                isBanned(),
                LastLogin(),
                Origination(),
                TitlePlayerAccount(nullptr)
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                AvatarUrl(src.AvatarUrl),
                Created(src.Created),
                DisplayName(src.DisplayName),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned),
                LastLogin(src.LastLogin),
                Origination(src.Origination),
                TitlePlayerAccount(src.TitlePlayerAccount ? new EntityKey(*src.TitlePlayerAccount) : nullptr)
            {}

            UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
            {
                readFromValue(obj);
            }

            ~UserTitleInfo()
            {
                if (TitlePlayerAccount != nullptr) delete TitlePlayerAccount;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AvatarUrl.length() > 0) {
                    writer.String("AvatarUrl");
                    writer.String(AvatarUrl.c_str());
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (FirstLogin.notNull()) {
                    writer.String("FirstLogin");
                    writeDatetime(FirstLogin, writer);
                }
                if (isBanned.notNull()) {
                    writer.String("isBanned");
                    writer.Bool(isBanned);
                }
                if (LastLogin.notNull()) {
                    writer.String("LastLogin");
                    writeDatetime(LastLogin, writer);
                }
                if (Origination.notNull()) {
                    writer.String("Origination");
                    writeUserOriginationEnumJSON(Origination, writer);
                }
                if (TitlePlayerAccount != nullptr) {
                    writer.String("TitlePlayerAccount");
                    TitlePlayerAccount->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator FirstLogin_member = obj.FindMember("FirstLogin");
                if (FirstLogin_member != obj.MemberEnd() && !FirstLogin_member->value.IsNull()) FirstLogin = readDatetime(FirstLogin_member->value);
                const Value::ConstMemberIterator isBanned_member = obj.FindMember("isBanned");
                if (isBanned_member != obj.MemberEnd() && !isBanned_member->value.IsNull()) isBanned = isBanned_member->value.GetBool();
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readUserOriginationFromValue(Origination_member->value);
                const Value::ConstMemberIterator TitlePlayerAccount_member = obj.FindMember("TitlePlayerAccount");
                if (TitlePlayerAccount_member != obj.MemberEnd() && !TitlePlayerAccount_member->value.IsNull()) TitlePlayerAccount = new EntityKey(TitlePlayerAccount_member->value);

                return true;
            }
        };

        struct UserTwitchInfo : public PlayFabBaseModel
        {
            AZStd::string TwitchId;
            AZStd::string TwitchUserName;

            UserTwitchInfo() :
                PlayFabBaseModel(),
                TwitchId(),
                TwitchUserName()
            {}

            UserTwitchInfo(const UserTwitchInfo& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                TwitchUserName(src.TwitchUserName)
            {}

            UserTwitchInfo(const rapidjson::Value& obj) : UserTwitchInfo()
            {
                readFromValue(obj);
            }

            ~UserTwitchInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (TwitchId.length() > 0) {
                    writer.String("TwitchId");
                    writer.String(TwitchId.c_str());
                }
                if (TwitchUserName.length() > 0) {
                    writer.String("TwitchUserName");
                    writer.String(TwitchUserName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TwitchId_member = obj.FindMember("TwitchId");
                if (TwitchId_member != obj.MemberEnd() && !TwitchId_member->value.IsNull()) TwitchId = TwitchId_member->value.GetString();
                const Value::ConstMemberIterator TwitchUserName_member = obj.FindMember("TwitchUserName");
                if (TwitchUserName_member != obj.MemberEnd() && !TwitchUserName_member->value.IsNull()) TwitchUserName = TwitchUserName_member->value.GetString();

                return true;
            }
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
            AZStd::string XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            UserXboxInfo(const rapidjson::Value& obj) : UserXboxInfo()
            {
                readFromValue(obj);
            }

            ~UserXboxInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (XboxUserId.length() > 0) {
                    writer.String("XboxUserId");
                    writer.String(XboxUserId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator XboxUserId_member = obj.FindMember("XboxUserId");
                if (XboxUserId_member != obj.MemberEnd() && !XboxUserId_member->value.IsNull()) XboxUserId = XboxUserId_member->value.GetString();

                return true;
            }
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            UserAndroidDeviceInfo* AndroidDeviceInfo;
            time_t Created;
            UserCustomIdInfo* CustomIdInfo;
            UserFacebookInfo* FacebookInfo;
            UserGameCenterInfo* GameCenterInfo;
            UserGoogleInfo* GoogleInfo;
            UserIosDeviceInfo* IosDeviceInfo;
            UserKongregateInfo* KongregateInfo;
            AZStd::string PlayFabId;
            UserPrivateAccountInfo* PrivateInfo;
            UserPsnInfo* PsnInfo;
            UserSteamInfo* SteamInfo;
            UserTitleInfo* TitleInfo;
            UserTwitchInfo* TwitchInfo;
            AZStd::string Username;
            UserXboxInfo* XboxInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                AndroidDeviceInfo(nullptr),
                Created(0),
                CustomIdInfo(nullptr),
                FacebookInfo(nullptr),
                GameCenterInfo(nullptr),
                GoogleInfo(nullptr),
                IosDeviceInfo(nullptr),
                KongregateInfo(nullptr),
                PlayFabId(),
                PrivateInfo(nullptr),
                PsnInfo(nullptr),
                SteamInfo(nullptr),
                TitleInfo(nullptr),
                TwitchInfo(nullptr),
                Username(),
                XboxInfo(nullptr)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : nullptr),
                Created(src.Created),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : nullptr),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : nullptr),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : nullptr),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : nullptr),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : nullptr),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : nullptr),
                PlayFabId(src.PlayFabId),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : nullptr),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : nullptr),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : nullptr),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : nullptr),
                TwitchInfo(src.TwitchInfo ? new UserTwitchInfo(*src.TwitchInfo) : nullptr),
                Username(src.Username),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : nullptr)
            {}

            UserAccountInfo(const rapidjson::Value& obj) : UserAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserAccountInfo()
            {
                if (AndroidDeviceInfo != nullptr) delete AndroidDeviceInfo;
                if (CustomIdInfo != nullptr) delete CustomIdInfo;
                if (FacebookInfo != nullptr) delete FacebookInfo;
                if (GameCenterInfo != nullptr) delete GameCenterInfo;
                if (GoogleInfo != nullptr) delete GoogleInfo;
                if (IosDeviceInfo != nullptr) delete IosDeviceInfo;
                if (KongregateInfo != nullptr) delete KongregateInfo;
                if (PrivateInfo != nullptr) delete PrivateInfo;
                if (PsnInfo != nullptr) delete PsnInfo;
                if (SteamInfo != nullptr) delete SteamInfo;
                if (TitleInfo != nullptr) delete TitleInfo;
                if (TwitchInfo != nullptr) delete TwitchInfo;
                if (XboxInfo != nullptr) delete XboxInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AndroidDeviceInfo != nullptr) {
                    writer.String("AndroidDeviceInfo");
                    AndroidDeviceInfo->writeJSON(writer);
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                if (CustomIdInfo != nullptr) {
                    writer.String("CustomIdInfo");
                    CustomIdInfo->writeJSON(writer);
                }
                if (FacebookInfo != nullptr) {
                    writer.String("FacebookInfo");
                    FacebookInfo->writeJSON(writer);
                }
                if (GameCenterInfo != nullptr) {
                    writer.String("GameCenterInfo");
                    GameCenterInfo->writeJSON(writer);
                }
                if (GoogleInfo != nullptr) {
                    writer.String("GoogleInfo");
                    GoogleInfo->writeJSON(writer);
                }
                if (IosDeviceInfo != nullptr) {
                    writer.String("IosDeviceInfo");
                    IosDeviceInfo->writeJSON(writer);
                }
                if (KongregateInfo != nullptr) {
                    writer.String("KongregateInfo");
                    KongregateInfo->writeJSON(writer);
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (PrivateInfo != nullptr) {
                    writer.String("PrivateInfo");
                    PrivateInfo->writeJSON(writer);
                }
                if (PsnInfo != nullptr) {
                    writer.String("PsnInfo");
                    PsnInfo->writeJSON(writer);
                }
                if (SteamInfo != nullptr) {
                    writer.String("SteamInfo");
                    SteamInfo->writeJSON(writer);
                }
                if (TitleInfo != nullptr) {
                    writer.String("TitleInfo");
                    TitleInfo->writeJSON(writer);
                }
                if (TwitchInfo != nullptr) {
                    writer.String("TwitchInfo");
                    TwitchInfo->writeJSON(writer);
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                if (XboxInfo != nullptr) {
                    writer.String("XboxInfo");
                    XboxInfo->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceInfo_member = obj.FindMember("AndroidDeviceInfo");
                if (AndroidDeviceInfo_member != obj.MemberEnd() && !AndroidDeviceInfo_member->value.IsNull()) AndroidDeviceInfo = new UserAndroidDeviceInfo(AndroidDeviceInfo_member->value);
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator CustomIdInfo_member = obj.FindMember("CustomIdInfo");
                if (CustomIdInfo_member != obj.MemberEnd() && !CustomIdInfo_member->value.IsNull()) CustomIdInfo = new UserCustomIdInfo(CustomIdInfo_member->value);
                const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
                if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
                const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
                if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
                const Value::ConstMemberIterator GoogleInfo_member = obj.FindMember("GoogleInfo");
                if (GoogleInfo_member != obj.MemberEnd() && !GoogleInfo_member->value.IsNull()) GoogleInfo = new UserGoogleInfo(GoogleInfo_member->value);
                const Value::ConstMemberIterator IosDeviceInfo_member = obj.FindMember("IosDeviceInfo");
                if (IosDeviceInfo_member != obj.MemberEnd() && !IosDeviceInfo_member->value.IsNull()) IosDeviceInfo = new UserIosDeviceInfo(IosDeviceInfo_member->value);
                const Value::ConstMemberIterator KongregateInfo_member = obj.FindMember("KongregateInfo");
                if (KongregateInfo_member != obj.MemberEnd() && !KongregateInfo_member->value.IsNull()) KongregateInfo = new UserKongregateInfo(KongregateInfo_member->value);
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator PrivateInfo_member = obj.FindMember("PrivateInfo");
                if (PrivateInfo_member != obj.MemberEnd() && !PrivateInfo_member->value.IsNull()) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
                const Value::ConstMemberIterator PsnInfo_member = obj.FindMember("PsnInfo");
                if (PsnInfo_member != obj.MemberEnd() && !PsnInfo_member->value.IsNull()) PsnInfo = new UserPsnInfo(PsnInfo_member->value);
                const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
                if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
                const Value::ConstMemberIterator TitleInfo_member = obj.FindMember("TitleInfo");
                if (TitleInfo_member != obj.MemberEnd() && !TitleInfo_member->value.IsNull()) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
                const Value::ConstMemberIterator TwitchInfo_member = obj.FindMember("TwitchInfo");
                if (TwitchInfo_member != obj.MemberEnd() && !TwitchInfo_member->value.IsNull()) TwitchInfo = new UserTwitchInfo(TwitchInfo_member->value);
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator XboxInfo_member = obj.FindMember("XboxInfo");
                if (XboxInfo_member != obj.MemberEnd() && !XboxInfo_member->value.IsNull()) XboxInfo = new UserXboxInfo(XboxInfo_member->value);

                return true;
            }
        };

        struct GetAccountInfoResult : public PlayFabBaseModel
        {
            UserAccountInfo* AccountInfo;

            GetAccountInfoResult() :
                PlayFabBaseModel(),
                AccountInfo(nullptr)
            {}

            GetAccountInfoResult(const GetAccountInfoResult& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : nullptr)
            {}

            GetAccountInfoResult(const rapidjson::Value& obj) : GetAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~GetAccountInfoResult()
            {
                if (AccountInfo != nullptr) delete AccountInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AccountInfo != nullptr) {
                    writer.String("AccountInfo");
                    AccountInfo->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccountInfo_member = obj.FindMember("AccountInfo");
                if (AccountInfo_member != obj.MemberEnd() && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);

                return true;
            }
        };

        struct GetCatalogItemsRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;

            GetCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCatalogItemsRequest(const rapidjson::Value& obj) : GetCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct GetCatalogItemsResult : public PlayFabBaseModel
        {
            AZStd::vector<CatalogItem> Catalog; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetCatalogItemsResult() :
                PlayFabBaseModel(),
                Catalog()
            {}

            GetCatalogItemsResult(const GetCatalogItemsResult& src) :
                PlayFabBaseModel(),
                Catalog(src.Catalog)
            {}

            GetCatalogItemsResult(const rapidjson::Value& obj) : GetCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Catalog.empty()) {
                    writer.String("Catalog");
                    writer.StartArray();
                    for (auto iter = Catalog.begin(); iter != Catalog.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Catalog_member = obj.FindMember("Catalog");
                if (Catalog_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Catalog_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Catalog.push_back(CatalogItem(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetCharacterDataRequest : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            OptionalUint32 IfChangedFromDataVersion;
            AZStd::vector<AZStd::string> Keys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string PlayFabId;

            GetCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
            {}

            GetCharacterDataRequest(const rapidjson::Value& obj) : GetCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (IfChangedFromDataVersion.notNull()) {
                    writer.String("IfChangedFromDataVersion");
                    writer.Uint(IfChangedFromDataVersion);
                }
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
                if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        inline void writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserDataPermissionPrivate: writer.String("Private"); break;
            case UserDataPermissionPublic: writer.String("Public"); break;

            }
        }

        inline UserDataPermission readUserDataPermissionFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<UserDataPermission>(obj.GetInt());

            static std::map<const char *, UserDataPermission, PlayFabClientSdk::StringCompare> _UserDataPermissionMap;
            if (_UserDataPermissionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserDataPermissionMap["Private"] = UserDataPermissionPrivate;
                _UserDataPermissionMap["Public"] = UserDataPermissionPublic;

            }

            auto output = _UserDataPermissionMap.find(obj.GetString());
            if (output != _UserDataPermissionMap.end())
                return output->second;

            return UserDataPermissionPrivate; // Basically critical fail
        }

        struct UserDataRecord : public PlayFabBaseModel
        {
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;
            AZStd::string Value;

            UserDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(0),
                Permission(),
                Value()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission),
                Value(src.Value)
            {}

            UserDataRecord(const rapidjson::Value& obj) : UserDataRecord()
            {
                readFromValue(obj);
            }

            ~UserDataRecord()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("LastUpdated");
                writeDatetime(LastUpdated, writer);
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                if (Value.length() > 0) {
                    writer.String("Value");
                    writer.String(Value.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
                if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct GetCharacterDataResult : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            std::map<AZStd::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetCharacterDataResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                DataVersion(0)
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            GetCharacterDataResult(const rapidjson::Value& obj) : GetCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct GetCharacterInventoryRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CharacterId;

            GetCharacterInventoryRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId)
            {}

            GetCharacterInventoryRequest(const rapidjson::Value& obj) : GetCharacterInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
            Int32 RechargeMax;
            time_t RechargeTime;
            Int32 SecondsToRecharge;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                RechargeMax(0),
                RechargeTime(0),
                SecondsToRecharge(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                RechargeMax(src.RechargeMax),
                RechargeTime(src.RechargeTime),
                SecondsToRecharge(src.SecondsToRecharge)
            {}

            VirtualCurrencyRechargeTime(const rapidjson::Value& obj) : VirtualCurrencyRechargeTime()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyRechargeTime()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("RechargeMax");
                writer.Int(RechargeMax);
                writer.String("RechargeTime");
                writeDatetime(RechargeTime, writer);
                writer.String("SecondsToRecharge");
                writer.Int(SecondsToRecharge);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
                if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();
                const Value::ConstMemberIterator RechargeTime_member = obj.FindMember("RechargeTime");
                if (RechargeTime_member != obj.MemberEnd() && !RechargeTime_member->value.IsNull()) RechargeTime = readDatetime(RechargeTime_member->value);
                const Value::ConstMemberIterator SecondsToRecharge_member = obj.FindMember("SecondsToRecharge");
                if (SecondsToRecharge_member != obj.MemberEnd() && !SecondsToRecharge_member->value.IsNull()) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();

                return true;
            }
        };

        struct GetCharacterInventoryResult : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            AZStd::vector<ItemInstance> Inventory; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, Int32> VirtualCurrency;
            std::map<AZStd::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetCharacterInventoryResult(const rapidjson::Value& obj) : GetCharacterInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (!Inventory.empty()) {
                    writer.String("Inventory");
                    writer.StartArray();
                    for (auto iter = Inventory.begin(); iter != Inventory.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyRechargeTimes.empty()) {
                    writer.String("VirtualCurrencyRechargeTimes");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
                if (Inventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Inventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Inventory.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
                if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
                    }
                }

                return true;
            }
        };

        struct GetCharacterLeaderboardRequest : public PlayFabBaseModel
        {
            AZStd::string CharacterType;
            OptionalInt32 MaxResultsCount;
            Int32 StartPosition;
            AZStd::string StatisticName;

            GetCharacterLeaderboardRequest() :
                PlayFabBaseModel(),
                CharacterType(),
                MaxResultsCount(),
                StartPosition(0),
                StatisticName()
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName)
            {}

            GetCharacterLeaderboardRequest(const rapidjson::Value& obj) : GetCharacterLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                writer.String("StartPosition");
                writer.Int(StartPosition);
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct GetCharacterLeaderboardResult : public PlayFabBaseModel
        {
            AZStd::vector<CharacterLeaderboardEntry> Leaderboard; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetCharacterLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetCharacterLeaderboardResult(const GetCharacterLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetCharacterLeaderboardResult(const rapidjson::Value& obj) : GetCharacterLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetCharacterStatisticsRequest : public PlayFabBaseModel
        {
            AZStd::string CharacterId;

            GetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId)
            {}

            GetCharacterStatisticsRequest(const rapidjson::Value& obj) : GetCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct GetCharacterStatisticsResult : public PlayFabBaseModel
        {
            std::map<AZStd::string, Int32> CharacterStatistics;

            GetCharacterStatisticsResult() :
                PlayFabBaseModel(),
                CharacterStatistics()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabBaseModel(),
                CharacterStatistics(src.CharacterStatistics)
            {}

            GetCharacterStatisticsResult(const rapidjson::Value& obj) : GetCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!CharacterStatistics.empty()) {
                    writer.String("CharacterStatistics");
                    writer.StartObject();
                    for (auto iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
                if (CharacterStatistics_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
                        CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
                    }
                }

                return true;
            }
        };

        struct GetContentDownloadUrlRequest : public PlayFabBaseModel
        {
            AZStd::string HttpMethod;
            AZStd::string Key;
            OptionalBool ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabBaseModel(),
                HttpMethod(),
                Key(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabBaseModel(),
                HttpMethod(src.HttpMethod),
                Key(src.Key),
                ThruCDN(src.ThruCDN)
            {}

            GetContentDownloadUrlRequest(const rapidjson::Value& obj) : GetContentDownloadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (HttpMethod.length() > 0) {
                    writer.String("HttpMethod");
                    writer.String(HttpMethod.c_str());
                }
                writer.String("Key");
                writer.String(Key.c_str());
                if (ThruCDN.notNull()) {
                    writer.String("ThruCDN");
                    writer.Bool(ThruCDN);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator HttpMethod_member = obj.FindMember("HttpMethod");
                if (HttpMethod_member != obj.MemberEnd() && !HttpMethod_member->value.IsNull()) HttpMethod = HttpMethod_member->value.GetString();
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator ThruCDN_member = obj.FindMember("ThruCDN");
                if (ThruCDN_member != obj.MemberEnd() && !ThruCDN_member->value.IsNull()) ThruCDN = ThruCDN_member->value.GetBool();

                return true;
            }
        };

        struct GetContentDownloadUrlResult : public PlayFabBaseModel
        {
            AZStd::string URL;

            GetContentDownloadUrlResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetContentDownloadUrlResult(const GetContentDownloadUrlResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetContentDownloadUrlResult(const rapidjson::Value& obj) : GetContentDownloadUrlResult()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (URL.length() > 0) {
                    writer.String("URL");
                    writer.String(URL.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
                if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

                return true;
            }
        };

        struct PlayerProfileViewConstraints : public PlayFabBaseModel
        {
            bool ShowAvatarUrl;
            bool ShowBannedUntil;
            bool ShowCampaignAttributions;
            bool ShowContactEmailAddresses;
            bool ShowCreated;
            bool ShowDisplayName;
            bool ShowLastLogin;
            bool ShowLinkedAccounts;
            bool ShowLocations;
            bool ShowMemberships;
            bool ShowOrigination;
            bool ShowPushNotificationRegistrations;
            bool ShowStatistics;
            bool ShowTags;
            bool ShowTotalValueToDateInUsd;
            bool ShowValuesToDate;

            PlayerProfileViewConstraints() :
                PlayFabBaseModel(),
                ShowAvatarUrl(false),
                ShowBannedUntil(false),
                ShowCampaignAttributions(false),
                ShowContactEmailAddresses(false),
                ShowCreated(false),
                ShowDisplayName(false),
                ShowLastLogin(false),
                ShowLinkedAccounts(false),
                ShowLocations(false),
                ShowMemberships(false),
                ShowOrigination(false),
                ShowPushNotificationRegistrations(false),
                ShowStatistics(false),
                ShowTags(false),
                ShowTotalValueToDateInUsd(false),
                ShowValuesToDate(false)
            {}

            PlayerProfileViewConstraints(const PlayerProfileViewConstraints& src) :
                PlayFabBaseModel(),
                ShowAvatarUrl(src.ShowAvatarUrl),
                ShowBannedUntil(src.ShowBannedUntil),
                ShowCampaignAttributions(src.ShowCampaignAttributions),
                ShowContactEmailAddresses(src.ShowContactEmailAddresses),
                ShowCreated(src.ShowCreated),
                ShowDisplayName(src.ShowDisplayName),
                ShowLastLogin(src.ShowLastLogin),
                ShowLinkedAccounts(src.ShowLinkedAccounts),
                ShowLocations(src.ShowLocations),
                ShowMemberships(src.ShowMemberships),
                ShowOrigination(src.ShowOrigination),
                ShowPushNotificationRegistrations(src.ShowPushNotificationRegistrations),
                ShowStatistics(src.ShowStatistics),
                ShowTags(src.ShowTags),
                ShowTotalValueToDateInUsd(src.ShowTotalValueToDateInUsd),
                ShowValuesToDate(src.ShowValuesToDate)
            {}

            PlayerProfileViewConstraints(const rapidjson::Value& obj) : PlayerProfileViewConstraints()
            {
                readFromValue(obj);
            }

            ~PlayerProfileViewConstraints()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ShowAvatarUrl");
                writer.Bool(ShowAvatarUrl);
                writer.String("ShowBannedUntil");
                writer.Bool(ShowBannedUntil);
                writer.String("ShowCampaignAttributions");
                writer.Bool(ShowCampaignAttributions);
                writer.String("ShowContactEmailAddresses");
                writer.Bool(ShowContactEmailAddresses);
                writer.String("ShowCreated");
                writer.Bool(ShowCreated);
                writer.String("ShowDisplayName");
                writer.Bool(ShowDisplayName);
                writer.String("ShowLastLogin");
                writer.Bool(ShowLastLogin);
                writer.String("ShowLinkedAccounts");
                writer.Bool(ShowLinkedAccounts);
                writer.String("ShowLocations");
                writer.Bool(ShowLocations);
                writer.String("ShowMemberships");
                writer.Bool(ShowMemberships);
                writer.String("ShowOrigination");
                writer.Bool(ShowOrigination);
                writer.String("ShowPushNotificationRegistrations");
                writer.Bool(ShowPushNotificationRegistrations);
                writer.String("ShowStatistics");
                writer.Bool(ShowStatistics);
                writer.String("ShowTags");
                writer.Bool(ShowTags);
                writer.String("ShowTotalValueToDateInUsd");
                writer.Bool(ShowTotalValueToDateInUsd);
                writer.String("ShowValuesToDate");
                writer.Bool(ShowValuesToDate);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ShowAvatarUrl_member = obj.FindMember("ShowAvatarUrl");
                if (ShowAvatarUrl_member != obj.MemberEnd() && !ShowAvatarUrl_member->value.IsNull()) ShowAvatarUrl = ShowAvatarUrl_member->value.GetBool();
                const Value::ConstMemberIterator ShowBannedUntil_member = obj.FindMember("ShowBannedUntil");
                if (ShowBannedUntil_member != obj.MemberEnd() && !ShowBannedUntil_member->value.IsNull()) ShowBannedUntil = ShowBannedUntil_member->value.GetBool();
                const Value::ConstMemberIterator ShowCampaignAttributions_member = obj.FindMember("ShowCampaignAttributions");
                if (ShowCampaignAttributions_member != obj.MemberEnd() && !ShowCampaignAttributions_member->value.IsNull()) ShowCampaignAttributions = ShowCampaignAttributions_member->value.GetBool();
                const Value::ConstMemberIterator ShowContactEmailAddresses_member = obj.FindMember("ShowContactEmailAddresses");
                if (ShowContactEmailAddresses_member != obj.MemberEnd() && !ShowContactEmailAddresses_member->value.IsNull()) ShowContactEmailAddresses = ShowContactEmailAddresses_member->value.GetBool();
                const Value::ConstMemberIterator ShowCreated_member = obj.FindMember("ShowCreated");
                if (ShowCreated_member != obj.MemberEnd() && !ShowCreated_member->value.IsNull()) ShowCreated = ShowCreated_member->value.GetBool();
                const Value::ConstMemberIterator ShowDisplayName_member = obj.FindMember("ShowDisplayName");
                if (ShowDisplayName_member != obj.MemberEnd() && !ShowDisplayName_member->value.IsNull()) ShowDisplayName = ShowDisplayName_member->value.GetBool();
                const Value::ConstMemberIterator ShowLastLogin_member = obj.FindMember("ShowLastLogin");
                if (ShowLastLogin_member != obj.MemberEnd() && !ShowLastLogin_member->value.IsNull()) ShowLastLogin = ShowLastLogin_member->value.GetBool();
                const Value::ConstMemberIterator ShowLinkedAccounts_member = obj.FindMember("ShowLinkedAccounts");
                if (ShowLinkedAccounts_member != obj.MemberEnd() && !ShowLinkedAccounts_member->value.IsNull()) ShowLinkedAccounts = ShowLinkedAccounts_member->value.GetBool();
                const Value::ConstMemberIterator ShowLocations_member = obj.FindMember("ShowLocations");
                if (ShowLocations_member != obj.MemberEnd() && !ShowLocations_member->value.IsNull()) ShowLocations = ShowLocations_member->value.GetBool();
                const Value::ConstMemberIterator ShowMemberships_member = obj.FindMember("ShowMemberships");
                if (ShowMemberships_member != obj.MemberEnd() && !ShowMemberships_member->value.IsNull()) ShowMemberships = ShowMemberships_member->value.GetBool();
                const Value::ConstMemberIterator ShowOrigination_member = obj.FindMember("ShowOrigination");
                if (ShowOrigination_member != obj.MemberEnd() && !ShowOrigination_member->value.IsNull()) ShowOrigination = ShowOrigination_member->value.GetBool();
                const Value::ConstMemberIterator ShowPushNotificationRegistrations_member = obj.FindMember("ShowPushNotificationRegistrations");
                if (ShowPushNotificationRegistrations_member != obj.MemberEnd() && !ShowPushNotificationRegistrations_member->value.IsNull()) ShowPushNotificationRegistrations = ShowPushNotificationRegistrations_member->value.GetBool();
                const Value::ConstMemberIterator ShowStatistics_member = obj.FindMember("ShowStatistics");
                if (ShowStatistics_member != obj.MemberEnd() && !ShowStatistics_member->value.IsNull()) ShowStatistics = ShowStatistics_member->value.GetBool();
                const Value::ConstMemberIterator ShowTags_member = obj.FindMember("ShowTags");
                if (ShowTags_member != obj.MemberEnd() && !ShowTags_member->value.IsNull()) ShowTags = ShowTags_member->value.GetBool();
                const Value::ConstMemberIterator ShowTotalValueToDateInUsd_member = obj.FindMember("ShowTotalValueToDateInUsd");
                if (ShowTotalValueToDateInUsd_member != obj.MemberEnd() && !ShowTotalValueToDateInUsd_member->value.IsNull()) ShowTotalValueToDateInUsd = ShowTotalValueToDateInUsd_member->value.GetBool();
                const Value::ConstMemberIterator ShowValuesToDate_member = obj.FindMember("ShowValuesToDate");
                if (ShowValuesToDate_member != obj.MemberEnd() && !ShowValuesToDate_member->value.IsNull()) ShowValuesToDate = ShowValuesToDate_member->value.GetBool();

                return true;
            }
        };

        struct GetFriendLeaderboardAroundPlayerRequest : public PlayFabBaseModel
        {
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            OptionalInt32 MaxResultsCount;
            AZStd::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;
            AZStd::string StatisticName;
            OptionalInt32 Version;

            GetFriendLeaderboardAroundPlayerRequest() :
                PlayFabBaseModel(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(nullptr),
                StatisticName(),
                Version()
            {}

            GetFriendLeaderboardAroundPlayerRequest(const GetFriendLeaderboardAroundPlayerRequest& src) :
                PlayFabBaseModel(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            GetFriendLeaderboardAroundPlayerRequest(const rapidjson::Value& obj) : GetFriendLeaderboardAroundPlayerRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundPlayerRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (IncludeFacebookFriends.notNull()) {
                    writer.String("IncludeFacebookFriends");
                    writer.Bool(IncludeFacebookFriends);
                }
                if (IncludeSteamFriends.notNull()) {
                    writer.String("IncludeSteamFriends");
                    writer.Bool(IncludeSteamFriends);
                }
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct PlayerLeaderboardEntry : public PlayFabBaseModel
        {
            AZStd::string DisplayName;
            AZStd::string PlayFabId;
            Int32 Position;
            PlayerProfileModel* Profile;
            Int32 StatValue;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                DisplayName(),
                PlayFabId(),
                Position(0),
                Profile(nullptr),
                StatValue(0)
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : nullptr),
                StatValue(src.StatValue)
            {}

            PlayerLeaderboardEntry(const rapidjson::Value& obj) : PlayerLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~PlayerLeaderboardEntry()
            {
                if (Profile != nullptr) delete Profile;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("Position");
                writer.Int(Position);
                if (Profile != nullptr) {
                    writer.String("Profile");
                    Profile->writeJSON(writer);
                }
                writer.String("StatValue");
                writer.Int(StatValue);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
                if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();
                const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
                if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new PlayerProfileModel(Profile_member->value);
                const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
                if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();

                return true;
            }
        };

        struct GetFriendLeaderboardAroundPlayerResult : public PlayFabBaseModel
        {
            AZStd::vector<PlayerLeaderboardEntry> Leaderboard; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalTime NextReset;
            Int32 Version;

            GetFriendLeaderboardAroundPlayerResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetFriendLeaderboardAroundPlayerResult(const GetFriendLeaderboardAroundPlayerResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            GetFriendLeaderboardAroundPlayerResult(const rapidjson::Value& obj) : GetFriendLeaderboardAroundPlayerResult()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundPlayerResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (NextReset.notNull()) {
                    writer.String("NextReset");
                    writeDatetime(NextReset, writer);
                }
                writer.String("Version");
                writer.Int(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct GetFriendLeaderboardRequest : public PlayFabBaseModel
        {
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            OptionalInt32 MaxResultsCount;
            PlayerProfileViewConstraints* ProfileConstraints;
            Int32 StartPosition;
            AZStd::string StatisticName;
            OptionalInt32 Version;

            GetFriendLeaderboardRequest() :
                PlayFabBaseModel(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                ProfileConstraints(nullptr),
                StartPosition(0),
                StatisticName(),
                Version()
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabBaseModel(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            GetFriendLeaderboardRequest(const rapidjson::Value& obj) : GetFriendLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (IncludeFacebookFriends.notNull()) {
                    writer.String("IncludeFacebookFriends");
                    writer.Bool(IncludeFacebookFriends);
                }
                if (IncludeSteamFriends.notNull()) {
                    writer.String("IncludeSteamFriends");
                    writer.Bool(IncludeSteamFriends);
                }
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.String("StartPosition");
                writer.Int(StartPosition);
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct GetFriendsListRequest : public PlayFabBaseModel
        {
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetFriendsListRequest() :
                PlayFabBaseModel(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                ProfileConstraints(nullptr)
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabBaseModel(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetFriendsListRequest(const rapidjson::Value& obj) : GetFriendsListRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendsListRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (IncludeFacebookFriends.notNull()) {
                    writer.String("IncludeFacebookFriends");
                    writer.Bool(IncludeFacebookFriends);
                }
                if (IncludeSteamFriends.notNull()) {
                    writer.String("IncludeSteamFriends");
                    writer.Bool(IncludeSteamFriends);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetFriendsListResult : public PlayFabBaseModel
        {
            AZStd::vector<FriendInfo> Friends; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetFriendsListResult() :
                PlayFabBaseModel(),
                Friends()
            {}

            GetFriendsListResult(const GetFriendsListResult& src) :
                PlayFabBaseModel(),
                Friends(src.Friends)
            {}

            GetFriendsListResult(const rapidjson::Value& obj) : GetFriendsListResult()
            {
                readFromValue(obj);
            }

            ~GetFriendsListResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Friends.empty()) {
                    writer.String("Friends");
                    writer.StartArray();
                    for (auto iter = Friends.begin(); iter != Friends.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Friends_member = obj.FindMember("Friends");
                if (Friends_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Friends_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Friends.push_back(FriendInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetLeaderboardAroundCharacterRequest : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            AZStd::string CharacterType;
            OptionalInt32 MaxResultsCount;
            AZStd::string StatisticName;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(),
                StatisticName()
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
            {}

            GetLeaderboardAroundCharacterRequest(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct GetLeaderboardAroundCharacterResult : public PlayFabBaseModel
        {
            AZStd::vector<CharacterLeaderboardEntry> Leaderboard; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetLeaderboardAroundCharacterResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardAroundCharacterResult(const GetLeaderboardAroundCharacterResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardAroundCharacterResult(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetLeaderboardAroundPlayerRequest : public PlayFabBaseModel
        {
            OptionalInt32 MaxResultsCount;
            AZStd::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;
            AZStd::string StatisticName;
            OptionalInt32 Version;

            GetLeaderboardAroundPlayerRequest() :
                PlayFabBaseModel(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(nullptr),
                StatisticName(),
                Version()
            {}

            GetLeaderboardAroundPlayerRequest(const GetLeaderboardAroundPlayerRequest& src) :
                PlayFabBaseModel(),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            GetLeaderboardAroundPlayerRequest(const rapidjson::Value& obj) : GetLeaderboardAroundPlayerRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundPlayerRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct GetLeaderboardAroundPlayerResult : public PlayFabBaseModel
        {
            AZStd::vector<PlayerLeaderboardEntry> Leaderboard; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalTime NextReset;
            Int32 Version;

            GetLeaderboardAroundPlayerResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetLeaderboardAroundPlayerResult(const GetLeaderboardAroundPlayerResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            GetLeaderboardAroundPlayerResult(const rapidjson::Value& obj) : GetLeaderboardAroundPlayerResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundPlayerResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (NextReset.notNull()) {
                    writer.String("NextReset");
                    writeDatetime(NextReset, writer);
                }
                writer.String("Version");
                writer.Int(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct GetLeaderboardForUsersCharactersRequest : public PlayFabBaseModel
        {
            Int32 MaxResultsCount;
            AZStd::string StatisticName;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabBaseModel(),
                MaxResultsCount(0),
                StatisticName()
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
            {}

            GetLeaderboardForUsersCharactersRequest(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("MaxResultsCount");
                writer.Int(MaxResultsCount);
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct GetLeaderboardForUsersCharactersResult : public PlayFabBaseModel
        {
            AZStd::vector<CharacterLeaderboardEntry> Leaderboard; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetLeaderboardForUsersCharactersResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardForUsersCharactersResult(const GetLeaderboardForUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardForUsersCharactersResult(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetLeaderboardRequest : public PlayFabBaseModel
        {
            OptionalInt32 MaxResultsCount;
            PlayerProfileViewConstraints* ProfileConstraints;
            Int32 StartPosition;
            AZStd::string StatisticName;
            OptionalInt32 Version;

            GetLeaderboardRequest() :
                PlayFabBaseModel(),
                MaxResultsCount(),
                ProfileConstraints(nullptr),
                StartPosition(0),
                StatisticName(),
                Version()
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabBaseModel(),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            GetLeaderboardRequest(const rapidjson::Value& obj) : GetLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.String("StartPosition");
                writer.Int(StartPosition);
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct GetLeaderboardResult : public PlayFabBaseModel
        {
            AZStd::vector<PlayerLeaderboardEntry> Leaderboard; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalTime NextReset;
            Int32 Version;

            GetLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            GetLeaderboardResult(const rapidjson::Value& obj) : GetLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (NextReset.notNull()) {
                    writer.String("NextReset");
                    writeDatetime(NextReset, writer);
                }
                writer.String("Version");
                writer.Int(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

                return true;
            }
        };

        struct GetPaymentTokenRequest : public PlayFabBaseModel
        {
            AZStd::string TokenProvider;

            GetPaymentTokenRequest() :
                PlayFabBaseModel(),
                TokenProvider()
            {}

            GetPaymentTokenRequest(const GetPaymentTokenRequest& src) :
                PlayFabBaseModel(),
                TokenProvider(src.TokenProvider)
            {}

            GetPaymentTokenRequest(const rapidjson::Value& obj) : GetPaymentTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetPaymentTokenRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("TokenProvider");
                writer.String(TokenProvider.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TokenProvider_member = obj.FindMember("TokenProvider");
                if (TokenProvider_member != obj.MemberEnd() && !TokenProvider_member->value.IsNull()) TokenProvider = TokenProvider_member->value.GetString();

                return true;
            }
        };

        struct GetPaymentTokenResult : public PlayFabBaseModel
        {
            AZStd::string OrderId;
            AZStd::string ProviderToken;

            GetPaymentTokenResult() :
                PlayFabBaseModel(),
                OrderId(),
                ProviderToken()
            {}

            GetPaymentTokenResult(const GetPaymentTokenResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                ProviderToken(src.ProviderToken)
            {}

            GetPaymentTokenResult(const rapidjson::Value& obj) : GetPaymentTokenResult()
            {
                readFromValue(obj);
            }

            ~GetPaymentTokenResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                if (ProviderToken.length() > 0) {
                    writer.String("ProviderToken");
                    writer.String(ProviderToken.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator ProviderToken_member = obj.FindMember("ProviderToken");
                if (ProviderToken_member != obj.MemberEnd() && !ProviderToken_member->value.IsNull()) ProviderToken = ProviderToken_member->value.GetString();

                return true;
            }
        };

        struct GetPhotonAuthenticationTokenRequest : public PlayFabBaseModel
        {
            AZStd::string PhotonApplicationId;

            GetPhotonAuthenticationTokenRequest() :
                PlayFabBaseModel(),
                PhotonApplicationId()
            {}

            GetPhotonAuthenticationTokenRequest(const GetPhotonAuthenticationTokenRequest& src) :
                PlayFabBaseModel(),
                PhotonApplicationId(src.PhotonApplicationId)
            {}

            GetPhotonAuthenticationTokenRequest(const rapidjson::Value& obj) : GetPhotonAuthenticationTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetPhotonAuthenticationTokenRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("PhotonApplicationId");
                writer.String(PhotonApplicationId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PhotonApplicationId_member = obj.FindMember("PhotonApplicationId");
                if (PhotonApplicationId_member != obj.MemberEnd() && !PhotonApplicationId_member->value.IsNull()) PhotonApplicationId = PhotonApplicationId_member->value.GetString();

                return true;
            }
        };

        struct GetPhotonAuthenticationTokenResult : public PlayFabBaseModel
        {
            AZStd::string PhotonCustomAuthenticationToken;

            GetPhotonAuthenticationTokenResult() :
                PlayFabBaseModel(),
                PhotonCustomAuthenticationToken()
            {}

            GetPhotonAuthenticationTokenResult(const GetPhotonAuthenticationTokenResult& src) :
                PlayFabBaseModel(),
                PhotonCustomAuthenticationToken(src.PhotonCustomAuthenticationToken)
            {}

            GetPhotonAuthenticationTokenResult(const rapidjson::Value& obj) : GetPhotonAuthenticationTokenResult()
            {
                readFromValue(obj);
            }

            ~GetPhotonAuthenticationTokenResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (PhotonCustomAuthenticationToken.length() > 0) {
                    writer.String("PhotonCustomAuthenticationToken");
                    writer.String(PhotonCustomAuthenticationToken.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PhotonCustomAuthenticationToken_member = obj.FindMember("PhotonCustomAuthenticationToken");
                if (PhotonCustomAuthenticationToken_member != obj.MemberEnd() && !PhotonCustomAuthenticationToken_member->value.IsNull()) PhotonCustomAuthenticationToken = PhotonCustomAuthenticationToken_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerCombinedInfoRequestParams : public PlayFabBaseModel
        {
            bool GetCharacterInventories;
            bool GetCharacterList;
            bool GetPlayerProfile;
            bool GetPlayerStatistics;
            bool GetTitleData;
            bool GetUserAccountInfo;
            bool GetUserData;
            bool GetUserInventory;
            bool GetUserReadOnlyData;
            bool GetUserVirtualCurrency;
            AZStd::vector<AZStd::string> PlayerStatisticNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            PlayerProfileViewConstraints* ProfileConstraints;
            AZStd::vector<AZStd::string> TitleDataKeys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> UserDataKeys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> UserReadOnlyDataKeys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerCombinedInfoRequestParams() :
                PlayFabBaseModel(),
                GetCharacterInventories(false),
                GetCharacterList(false),
                GetPlayerProfile(false),
                GetPlayerStatistics(false),
                GetTitleData(false),
                GetUserAccountInfo(false),
                GetUserData(false),
                GetUserInventory(false),
                GetUserReadOnlyData(false),
                GetUserVirtualCurrency(false),
                PlayerStatisticNames(),
                ProfileConstraints(nullptr),
                TitleDataKeys(),
                UserDataKeys(),
                UserReadOnlyDataKeys()
            {}

            GetPlayerCombinedInfoRequestParams(const GetPlayerCombinedInfoRequestParams& src) :
                PlayFabBaseModel(),
                GetCharacterInventories(src.GetCharacterInventories),
                GetCharacterList(src.GetCharacterList),
                GetPlayerProfile(src.GetPlayerProfile),
                GetPlayerStatistics(src.GetPlayerStatistics),
                GetTitleData(src.GetTitleData),
                GetUserAccountInfo(src.GetUserAccountInfo),
                GetUserData(src.GetUserData),
                GetUserInventory(src.GetUserInventory),
                GetUserReadOnlyData(src.GetUserReadOnlyData),
                GetUserVirtualCurrency(src.GetUserVirtualCurrency),
                PlayerStatisticNames(src.PlayerStatisticNames),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr),
                TitleDataKeys(src.TitleDataKeys),
                UserDataKeys(src.UserDataKeys),
                UserReadOnlyDataKeys(src.UserReadOnlyDataKeys)
            {}

            GetPlayerCombinedInfoRequestParams(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequestParams()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequestParams()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GetCharacterInventories");
                writer.Bool(GetCharacterInventories);
                writer.String("GetCharacterList");
                writer.Bool(GetCharacterList);
                writer.String("GetPlayerProfile");
                writer.Bool(GetPlayerProfile);
                writer.String("GetPlayerStatistics");
                writer.Bool(GetPlayerStatistics);
                writer.String("GetTitleData");
                writer.Bool(GetTitleData);
                writer.String("GetUserAccountInfo");
                writer.Bool(GetUserAccountInfo);
                writer.String("GetUserData");
                writer.Bool(GetUserData);
                writer.String("GetUserInventory");
                writer.Bool(GetUserInventory);
                writer.String("GetUserReadOnlyData");
                writer.Bool(GetUserReadOnlyData);
                writer.String("GetUserVirtualCurrency");
                writer.Bool(GetUserVirtualCurrency);
                if (!PlayerStatisticNames.empty()) {
                    writer.String("PlayerStatisticNames");
                    writer.StartArray();
                    for (auto iter = PlayerStatisticNames.begin(); iter != PlayerStatisticNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                if (!TitleDataKeys.empty()) {
                    writer.String("TitleDataKeys");
                    writer.StartArray();
                    for (auto iter = TitleDataKeys.begin(); iter != TitleDataKeys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!UserDataKeys.empty()) {
                    writer.String("UserDataKeys");
                    writer.StartArray();
                    for (auto iter = UserDataKeys.begin(); iter != UserDataKeys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!UserReadOnlyDataKeys.empty()) {
                    writer.String("UserReadOnlyDataKeys");
                    writer.StartArray();
                    for (auto iter = UserReadOnlyDataKeys.begin(); iter != UserReadOnlyDataKeys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GetCharacterInventories_member = obj.FindMember("GetCharacterInventories");
                if (GetCharacterInventories_member != obj.MemberEnd() && !GetCharacterInventories_member->value.IsNull()) GetCharacterInventories = GetCharacterInventories_member->value.GetBool();
                const Value::ConstMemberIterator GetCharacterList_member = obj.FindMember("GetCharacterList");
                if (GetCharacterList_member != obj.MemberEnd() && !GetCharacterList_member->value.IsNull()) GetCharacterList = GetCharacterList_member->value.GetBool();
                const Value::ConstMemberIterator GetPlayerProfile_member = obj.FindMember("GetPlayerProfile");
                if (GetPlayerProfile_member != obj.MemberEnd() && !GetPlayerProfile_member->value.IsNull()) GetPlayerProfile = GetPlayerProfile_member->value.GetBool();
                const Value::ConstMemberIterator GetPlayerStatistics_member = obj.FindMember("GetPlayerStatistics");
                if (GetPlayerStatistics_member != obj.MemberEnd() && !GetPlayerStatistics_member->value.IsNull()) GetPlayerStatistics = GetPlayerStatistics_member->value.GetBool();
                const Value::ConstMemberIterator GetTitleData_member = obj.FindMember("GetTitleData");
                if (GetTitleData_member != obj.MemberEnd() && !GetTitleData_member->value.IsNull()) GetTitleData = GetTitleData_member->value.GetBool();
                const Value::ConstMemberIterator GetUserAccountInfo_member = obj.FindMember("GetUserAccountInfo");
                if (GetUserAccountInfo_member != obj.MemberEnd() && !GetUserAccountInfo_member->value.IsNull()) GetUserAccountInfo = GetUserAccountInfo_member->value.GetBool();
                const Value::ConstMemberIterator GetUserData_member = obj.FindMember("GetUserData");
                if (GetUserData_member != obj.MemberEnd() && !GetUserData_member->value.IsNull()) GetUserData = GetUserData_member->value.GetBool();
                const Value::ConstMemberIterator GetUserInventory_member = obj.FindMember("GetUserInventory");
                if (GetUserInventory_member != obj.MemberEnd() && !GetUserInventory_member->value.IsNull()) GetUserInventory = GetUserInventory_member->value.GetBool();
                const Value::ConstMemberIterator GetUserReadOnlyData_member = obj.FindMember("GetUserReadOnlyData");
                if (GetUserReadOnlyData_member != obj.MemberEnd() && !GetUserReadOnlyData_member->value.IsNull()) GetUserReadOnlyData = GetUserReadOnlyData_member->value.GetBool();
                const Value::ConstMemberIterator GetUserVirtualCurrency_member = obj.FindMember("GetUserVirtualCurrency");
                if (GetUserVirtualCurrency_member != obj.MemberEnd() && !GetUserVirtualCurrency_member->value.IsNull()) GetUserVirtualCurrency = GetUserVirtualCurrency_member->value.GetBool();
                const Value::ConstMemberIterator PlayerStatisticNames_member = obj.FindMember("PlayerStatisticNames");
                if (PlayerStatisticNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerStatisticNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerStatisticNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
                const Value::ConstMemberIterator TitleDataKeys_member = obj.FindMember("TitleDataKeys");
                if (TitleDataKeys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = TitleDataKeys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        TitleDataKeys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator UserDataKeys_member = obj.FindMember("UserDataKeys");
                if (UserDataKeys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UserDataKeys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UserDataKeys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator UserReadOnlyDataKeys_member = obj.FindMember("UserReadOnlyDataKeys");
                if (UserReadOnlyDataKeys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UserReadOnlyDataKeys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UserReadOnlyDataKeys.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPlayerCombinedInfoRequest : public PlayFabBaseModel
        {
            GetPlayerCombinedInfoRequestParams InfoRequestParameters;
            AZStd::string PlayFabId;

            GetPlayerCombinedInfoRequest() :
                PlayFabBaseModel(),
                InfoRequestParameters(),
                PlayFabId()
            {}

            GetPlayerCombinedInfoRequest(const GetPlayerCombinedInfoRequest& src) :
                PlayFabBaseModel(),
                InfoRequestParameters(src.InfoRequestParameters),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerCombinedInfoRequest(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("InfoRequestParameters");
                InfoRequestParameters.writeJSON(writer);
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct StatisticValue : public PlayFabBaseModel
        {
            AZStd::string StatisticName;
            Int32 Value;
            Uint32 Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version(0)
            {}

            StatisticValue(const StatisticValue& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticValue(const rapidjson::Value& obj) : StatisticValue()
            {
                readFromValue(obj);
            }

            ~StatisticValue()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.String("Value");
                writer.Int(Value);
                writer.String("Version");
                writer.Uint(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct GetPlayerCombinedInfoResultPayload : public PlayFabBaseModel
        {
            UserAccountInfo* AccountInfo;
            AZStd::vector<CharacterInventory> CharacterInventories; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<CharacterResult> CharacterList; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            PlayerProfileModel* PlayerProfile;
            AZStd::vector<StatisticValue> PlayerStatistics; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, AZStd::string> TitleData;
            std::map<AZStd::string, UserDataRecord> UserData;
            Uint32 UserDataVersion;
            AZStd::vector<ItemInstance> UserInventory; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, UserDataRecord> UserReadOnlyData;
            Uint32 UserReadOnlyDataVersion;
            std::map<AZStd::string, Int32> UserVirtualCurrency;
            std::map<AZStd::string, VirtualCurrencyRechargeTime> UserVirtualCurrencyRechargeTimes;

            GetPlayerCombinedInfoResultPayload() :
                PlayFabBaseModel(),
                AccountInfo(nullptr),
                CharacterInventories(),
                CharacterList(),
                PlayerProfile(nullptr),
                PlayerStatistics(),
                TitleData(),
                UserData(),
                UserDataVersion(0),
                UserInventory(),
                UserReadOnlyData(),
                UserReadOnlyDataVersion(0),
                UserVirtualCurrency(),
                UserVirtualCurrencyRechargeTimes()
            {}

            GetPlayerCombinedInfoResultPayload(const GetPlayerCombinedInfoResultPayload& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : nullptr),
                CharacterInventories(src.CharacterInventories),
                CharacterList(src.CharacterList),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : nullptr),
                PlayerStatistics(src.PlayerStatistics),
                TitleData(src.TitleData),
                UserData(src.UserData),
                UserDataVersion(src.UserDataVersion),
                UserInventory(src.UserInventory),
                UserReadOnlyData(src.UserReadOnlyData),
                UserReadOnlyDataVersion(src.UserReadOnlyDataVersion),
                UserVirtualCurrency(src.UserVirtualCurrency),
                UserVirtualCurrencyRechargeTimes(src.UserVirtualCurrencyRechargeTimes)
            {}

            GetPlayerCombinedInfoResultPayload(const rapidjson::Value& obj) : GetPlayerCombinedInfoResultPayload()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResultPayload()
            {
                if (AccountInfo != nullptr) delete AccountInfo;
                if (PlayerProfile != nullptr) delete PlayerProfile;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AccountInfo != nullptr) {
                    writer.String("AccountInfo");
                    AccountInfo->writeJSON(writer);
                }
                if (!CharacterInventories.empty()) {
                    writer.String("CharacterInventories");
                    writer.StartArray();
                    for (auto iter = CharacterInventories.begin(); iter != CharacterInventories.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!CharacterList.empty()) {
                    writer.String("CharacterList");
                    writer.StartArray();
                    for (auto iter = CharacterList.begin(); iter != CharacterList.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (PlayerProfile != nullptr) {
                    writer.String("PlayerProfile");
                    PlayerProfile->writeJSON(writer);
                }
                if (!PlayerStatistics.empty()) {
                    writer.String("PlayerStatistics");
                    writer.StartArray();
                    for (auto iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!TitleData.empty()) {
                    writer.String("TitleData");
                    writer.StartObject();
                    for (auto iter = TitleData.begin(); iter != TitleData.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!UserData.empty()) {
                    writer.String("UserData");
                    writer.StartObject();
                    for (auto iter = UserData.begin(); iter != UserData.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("UserDataVersion");
                writer.Uint(UserDataVersion);
                if (!UserInventory.empty()) {
                    writer.String("UserInventory");
                    writer.StartArray();
                    for (auto iter = UserInventory.begin(); iter != UserInventory.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!UserReadOnlyData.empty()) {
                    writer.String("UserReadOnlyData");
                    writer.StartObject();
                    for (auto iter = UserReadOnlyData.begin(); iter != UserReadOnlyData.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("UserReadOnlyDataVersion");
                writer.Uint(UserReadOnlyDataVersion);
                if (!UserVirtualCurrency.empty()) {
                    writer.String("UserVirtualCurrency");
                    writer.StartObject();
                    for (auto iter = UserVirtualCurrency.begin(); iter != UserVirtualCurrency.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!UserVirtualCurrencyRechargeTimes.empty()) {
                    writer.String("UserVirtualCurrencyRechargeTimes");
                    writer.StartObject();
                    for (auto iter = UserVirtualCurrencyRechargeTimes.begin(); iter != UserVirtualCurrencyRechargeTimes.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccountInfo_member = obj.FindMember("AccountInfo");
                if (AccountInfo_member != obj.MemberEnd() && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);
                const Value::ConstMemberIterator CharacterInventories_member = obj.FindMember("CharacterInventories");
                if (CharacterInventories_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = CharacterInventories_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        CharacterInventories.push_back(CharacterInventory(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator CharacterList_member = obj.FindMember("CharacterList");
                if (CharacterList_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = CharacterList_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        CharacterList.push_back(CharacterResult(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
                if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);
                const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
                if (PlayerStatistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerStatistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerStatistics.push_back(StatisticValue(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator TitleData_member = obj.FindMember("TitleData");
                if (TitleData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = TitleData_member->value.MemberBegin(); iter != TitleData_member->value.MemberEnd(); ++iter) {
                        TitleData[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator UserData_member = obj.FindMember("UserData");
                if (UserData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserData_member->value.MemberBegin(); iter != UserData_member->value.MemberEnd(); ++iter) {
                        UserData[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator UserDataVersion_member = obj.FindMember("UserDataVersion");
                if (UserDataVersion_member != obj.MemberEnd() && !UserDataVersion_member->value.IsNull()) UserDataVersion = UserDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator UserInventory_member = obj.FindMember("UserInventory");
                if (UserInventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UserInventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UserInventory.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator UserReadOnlyData_member = obj.FindMember("UserReadOnlyData");
                if (UserReadOnlyData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserReadOnlyData_member->value.MemberBegin(); iter != UserReadOnlyData_member->value.MemberEnd(); ++iter) {
                        UserReadOnlyData[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator UserReadOnlyDataVersion_member = obj.FindMember("UserReadOnlyDataVersion");
                if (UserReadOnlyDataVersion_member != obj.MemberEnd() && !UserReadOnlyDataVersion_member->value.IsNull()) UserReadOnlyDataVersion = UserReadOnlyDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator UserVirtualCurrency_member = obj.FindMember("UserVirtualCurrency");
                if (UserVirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserVirtualCurrency_member->value.MemberBegin(); iter != UserVirtualCurrency_member->value.MemberEnd(); ++iter) {
                        UserVirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator UserVirtualCurrencyRechargeTimes_member = obj.FindMember("UserVirtualCurrencyRechargeTimes");
                if (UserVirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserVirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != UserVirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
                        UserVirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
                    }
                }

                return true;
            }
        };

        struct GetPlayerCombinedInfoResult : public PlayFabBaseModel
        {
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;
            AZStd::string PlayFabId;

            GetPlayerCombinedInfoResult() :
                PlayFabBaseModel(),
                InfoResultPayload(nullptr),
                PlayFabId()
            {}

            GetPlayerCombinedInfoResult(const GetPlayerCombinedInfoResult& src) :
                PlayFabBaseModel(),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : nullptr),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerCombinedInfoResult(const rapidjson::Value& obj) : GetPlayerCombinedInfoResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResult()
            {
                if (InfoResultPayload != nullptr) delete InfoResultPayload;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (InfoResultPayload != nullptr) {
                    writer.String("InfoResultPayload");
                    InfoResultPayload->writeJSON(writer);
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
                if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerProfileRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetPlayerProfileRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                ProfileConstraints(nullptr)
            {}

            GetPlayerProfileRequest(const GetPlayerProfileRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetPlayerProfileRequest(const rapidjson::Value& obj) : GetPlayerProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetPlayerProfileResult : public PlayFabBaseModel
        {
            PlayerProfileModel* PlayerProfile;

            GetPlayerProfileResult() :
                PlayFabBaseModel(),
                PlayerProfile(nullptr)
            {}

            GetPlayerProfileResult(const GetPlayerProfileResult& src) :
                PlayFabBaseModel(),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : nullptr)
            {}

            GetPlayerProfileResult(const rapidjson::Value& obj) : GetPlayerProfileResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileResult()
            {
                if (PlayerProfile != nullptr) delete PlayerProfile;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (PlayerProfile != nullptr) {
                    writer.String("PlayerProfile");
                    PlayerProfile->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
                if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);

                return true;
            }
        };

        struct GetPlayerSegmentsRequest : public PlayFabBaseModel
        {

            GetPlayerSegmentsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerSegmentsRequest(const GetPlayerSegmentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerSegmentsRequest(const rapidjson::Value& obj) : GetPlayerSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetSegmentResult : public PlayFabBaseModel
        {
            AZStd::string ABTestParent;
            AZStd::string Id;
            AZStd::string Name;

            GetSegmentResult() :
                PlayFabBaseModel(),
                ABTestParent(),
                Id(),
                Name()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabBaseModel(),
                ABTestParent(src.ABTestParent),
                Id(src.Id),
                Name(src.Name)
            {}

            GetSegmentResult(const rapidjson::Value& obj) : GetSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetSegmentResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ABTestParent.length() > 0) {
                    writer.String("ABTestParent");
                    writer.String(ABTestParent.c_str());
                }
                writer.String("Id");
                writer.String(Id.c_str());
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ABTestParent_member = obj.FindMember("ABTestParent");
                if (ABTestParent_member != obj.MemberEnd() && !ABTestParent_member->value.IsNull()) ABTestParent = ABTestParent_member->value.GetString();
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerSegmentsResult : public PlayFabBaseModel
        {
            AZStd::vector<GetSegmentResult> Segments; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetPlayerSegmentsResult(const GetPlayerSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetPlayerSegmentsResult(const rapidjson::Value& obj) : GetPlayerSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Segments.empty()) {
                    writer.String("Segments");
                    writer.StartArray();
                    for (auto iter = Segments.begin(); iter != Segments.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Segments_member = obj.FindMember("Segments");
                if (Segments_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Segments_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Segments.push_back(GetSegmentResult(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct StatisticNameVersion : public PlayFabBaseModel
        {
            AZStd::string StatisticName;
            Uint32 Version;

            StatisticNameVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0)
            {}

            StatisticNameVersion(const StatisticNameVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            StatisticNameVersion(const rapidjson::Value& obj) : StatisticNameVersion()
            {
                readFromValue(obj);
            }

            ~StatisticNameVersion()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("Version");
                writer.Uint(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct GetPlayerStatisticsRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> StatisticNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<StatisticNameVersion> StatisticNameVersions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerStatisticsRequest() :
                PlayFabBaseModel(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            GetPlayerStatisticsRequest(const rapidjson::Value& obj) : GetPlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!StatisticNames.empty()) {
                    writer.String("StatisticNames");
                    writer.StartArray();
                    for (auto iter = StatisticNames.begin(); iter != StatisticNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!StatisticNameVersions.empty()) {
                    writer.String("StatisticNameVersions");
                    writer.StartArray();
                    for (auto iter = StatisticNameVersions.begin(); iter != StatisticNameVersions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticNames_member = obj.FindMember("StatisticNames");
                if (StatisticNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = StatisticNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        StatisticNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator StatisticNameVersions_member = obj.FindMember("StatisticNameVersions");
                if (StatisticNameVersions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = StatisticNameVersions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        StatisticNameVersions.push_back(StatisticNameVersion(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerStatisticsResult : public PlayFabBaseModel
        {
            AZStd::vector<StatisticValue> Statistics; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerStatisticsResult() :
                PlayFabBaseModel(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticsResult(const rapidjson::Value& obj) : GetPlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Statistics.empty()) {
                    writer.String("Statistics");
                    writer.StartArray();
                    for (auto iter = Statistics.begin(); iter != Statistics.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
                if (Statistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statistics.push_back(StatisticValue(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabBaseModel
        {
            AZStd::string StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName)
            {}

            GetPlayerStatisticVersionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            time_t ActivationTime;
            OptionalTime DeactivationTime;
            OptionalTime ScheduledActivationTime;
            OptionalTime ScheduledDeactivationTime;
            AZStd::string StatisticName;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(0),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Version(0)
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            PlayerStatisticVersion(const rapidjson::Value& obj) : PlayerStatisticVersion()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticVersion()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ActivationTime");
                writeDatetime(ActivationTime, writer);
                if (DeactivationTime.notNull()) {
                    writer.String("DeactivationTime");
                    writeDatetime(DeactivationTime, writer);
                }
                if (ScheduledActivationTime.notNull()) {
                    writer.String("ScheduledActivationTime");
                    writeDatetime(ScheduledActivationTime, writer);
                }
                if (ScheduledDeactivationTime.notNull()) {
                    writer.String("ScheduledDeactivationTime");
                    writeDatetime(ScheduledDeactivationTime, writer);
                }
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.String("Version");
                writer.Uint(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ActivationTime_member = obj.FindMember("ActivationTime");
                if (ActivationTime_member != obj.MemberEnd() && !ActivationTime_member->value.IsNull()) ActivationTime = readDatetime(ActivationTime_member->value);
                const Value::ConstMemberIterator DeactivationTime_member = obj.FindMember("DeactivationTime");
                if (DeactivationTime_member != obj.MemberEnd() && !DeactivationTime_member->value.IsNull()) DeactivationTime = readDatetime(DeactivationTime_member->value);
                const Value::ConstMemberIterator ScheduledActivationTime_member = obj.FindMember("ScheduledActivationTime");
                if (ScheduledActivationTime_member != obj.MemberEnd() && !ScheduledActivationTime_member->value.IsNull()) ScheduledActivationTime = readDatetime(ScheduledActivationTime_member->value);
                const Value::ConstMemberIterator ScheduledDeactivationTime_member = obj.FindMember("ScheduledDeactivationTime");
                if (ScheduledDeactivationTime_member != obj.MemberEnd() && !ScheduledDeactivationTime_member->value.IsNull()) ScheduledDeactivationTime = readDatetime(ScheduledDeactivationTime_member->value);
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabBaseModel
        {
            AZStd::vector<PlayerStatisticVersion> StatisticVersions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerStatisticVersionsResult() :
                PlayFabBaseModel(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabBaseModel(),
                StatisticVersions(src.StatisticVersions)
            {}

            GetPlayerStatisticVersionsResult(const rapidjson::Value& obj) : GetPlayerStatisticVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!StatisticVersions.empty()) {
                    writer.String("StatisticVersions");
                    writer.StartArray();
                    for (auto iter = StatisticVersions.begin(); iter != StatisticVersions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticVersions_member = obj.FindMember("StatisticVersions");
                if (StatisticVersions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = StatisticVersions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        StatisticVersions.push_back(PlayerStatisticVersion(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerTagsRequest : public PlayFabBaseModel
        {
            AZStd::string Namespace;
            AZStd::string PlayFabId;

            GetPlayerTagsRequest() :
                PlayFabBaseModel(),
                Namespace(),
                PlayFabId()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabBaseModel(),
                Namespace(src.Namespace),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerTagsRequest(const rapidjson::Value& obj) : GetPlayerTagsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Namespace.length() > 0) {
                    writer.String("Namespace");
                    writer.String(Namespace.c_str());
                }
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Namespace_member = obj.FindMember("Namespace");
                if (Namespace_member != obj.MemberEnd() && !Namespace_member->value.IsNull()) Namespace = Namespace_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerTagsResult : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::vector<AZStd::string> Tags; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerTagsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Tags()
            {}

            GetPlayerTagsResult(const GetPlayerTagsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            GetPlayerTagsResult(const rapidjson::Value& obj) : GetPlayerTagsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("Tags");
                writer.StartArray();
                for (auto iter = Tags.begin(); iter != Tags.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPlayerTradesRequest : public PlayFabBaseModel
        {
            Boxed<TradeStatus> StatusFilter;

            GetPlayerTradesRequest() :
                PlayFabBaseModel(),
                StatusFilter()
            {}

            GetPlayerTradesRequest(const GetPlayerTradesRequest& src) :
                PlayFabBaseModel(),
                StatusFilter(src.StatusFilter)
            {}

            GetPlayerTradesRequest(const rapidjson::Value& obj) : GetPlayerTradesRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTradesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (StatusFilter.notNull()) {
                    writer.String("StatusFilter");
                    writeTradeStatusEnumJSON(StatusFilter, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatusFilter_member = obj.FindMember("StatusFilter");
                if (StatusFilter_member != obj.MemberEnd() && !StatusFilter_member->value.IsNull()) StatusFilter = readTradeStatusFromValue(StatusFilter_member->value);

                return true;
            }
        };

        struct GetPlayerTradesResponse : public PlayFabBaseModel
        {
            AZStd::vector<TradeInfo> AcceptedTrades; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<TradeInfo> OpenedTrades; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerTradesResponse() :
                PlayFabBaseModel(),
                AcceptedTrades(),
                OpenedTrades()
            {}

            GetPlayerTradesResponse(const GetPlayerTradesResponse& src) :
                PlayFabBaseModel(),
                AcceptedTrades(src.AcceptedTrades),
                OpenedTrades(src.OpenedTrades)
            {}

            GetPlayerTradesResponse(const rapidjson::Value& obj) : GetPlayerTradesResponse()
            {
                readFromValue(obj);
            }

            ~GetPlayerTradesResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!AcceptedTrades.empty()) {
                    writer.String("AcceptedTrades");
                    writer.StartArray();
                    for (auto iter = AcceptedTrades.begin(); iter != AcceptedTrades.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!OpenedTrades.empty()) {
                    writer.String("OpenedTrades");
                    writer.StartArray();
                    for (auto iter = OpenedTrades.begin(); iter != OpenedTrades.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AcceptedTrades_member = obj.FindMember("AcceptedTrades");
                if (AcceptedTrades_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AcceptedTrades_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AcceptedTrades.push_back(TradeInfo(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator OpenedTrades_member = obj.FindMember("OpenedTrades");
                if (OpenedTrades_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OpenedTrades_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OpenedTrades.push_back(TradeInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> FacebookIDs; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromFacebookIDsRequest() :
                PlayFabBaseModel(),
                FacebookIDs()
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const GetPlayFabIDsFromFacebookIDsRequest& src) :
                PlayFabBaseModel(),
                FacebookIDs(src.FacebookIDs)
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("FacebookIDs");
                writer.StartArray();
                for (auto iter = FacebookIDs.begin(); iter != FacebookIDs.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookIDs_member = obj.FindMember("FacebookIDs");
                if (FacebookIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FacebookIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FacebookIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsResult : public PlayFabBaseModel
        {
            AZStd::vector<FacebookPlayFabIdPair> Data; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromFacebookIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromFacebookIDsResult(const GetPlayFabIDsFromFacebookIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromFacebookIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(FacebookPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> GameCenterIDs; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGameCenterIDsRequest() :
                PlayFabBaseModel(),
                GameCenterIDs()
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const GetPlayFabIDsFromGameCenterIDsRequest& src) :
                PlayFabBaseModel(),
                GameCenterIDs(src.GameCenterIDs)
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGameCenterIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGameCenterIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GameCenterIDs");
                writer.StartArray();
                for (auto iter = GameCenterIDs.begin(); iter != GameCenterIDs.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterIDs_member = obj.FindMember("GameCenterIDs");
                if (GameCenterIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GameCenterIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GameCenterIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsResult : public PlayFabBaseModel
        {
            AZStd::vector<GameCenterPlayFabIdPair> Data; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGameCenterIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const GetPlayFabIDsFromGameCenterIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGameCenterIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGameCenterIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(GameCenterPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGenericIDsRequest : public PlayFabBaseModel
        {
            AZStd::vector<GenericServiceId> GenericIDs; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGenericIDsRequest() :
                PlayFabBaseModel(),
                GenericIDs()
            {}

            GetPlayFabIDsFromGenericIDsRequest(const GetPlayFabIDsFromGenericIDsRequest& src) :
                PlayFabBaseModel(),
                GenericIDs(src.GenericIDs)
            {}

            GetPlayFabIDsFromGenericIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGenericIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGenericIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GenericIDs");
                writer.StartArray();
                for (auto iter = GenericIDs.begin(); iter != GenericIDs.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericIDs_member = obj.FindMember("GenericIDs");
                if (GenericIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GenericIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GenericIDs.push_back(GenericServiceId(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGenericIDsResult : public PlayFabBaseModel
        {
            AZStd::vector<GenericPlayFabIdPair> Data; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGenericIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGenericIDsResult(const GetPlayFabIDsFromGenericIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGenericIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGenericIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGenericIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(GenericPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> GoogleIDs; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGoogleIDsRequest() :
                PlayFabBaseModel(),
                GoogleIDs()
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const GetPlayFabIDsFromGoogleIDsRequest& src) :
                PlayFabBaseModel(),
                GoogleIDs(src.GoogleIDs)
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGoogleIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGoogleIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GoogleIDs");
                writer.StartArray();
                for (auto iter = GoogleIDs.begin(); iter != GoogleIDs.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleIDs_member = obj.FindMember("GoogleIDs");
                if (GoogleIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GoogleIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GoogleIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GooglePlayFabIdPair : public PlayFabBaseModel
        {
            AZStd::string GoogleId;
            AZStd::string PlayFabId;

            GooglePlayFabIdPair() :
                PlayFabBaseModel(),
                GoogleId(),
                PlayFabId()
            {}

            GooglePlayFabIdPair(const GooglePlayFabIdPair& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                PlayFabId(src.PlayFabId)
            {}

            GooglePlayFabIdPair(const rapidjson::Value& obj) : GooglePlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GooglePlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (GoogleId.length() > 0) {
                    writer.String("GoogleId");
                    writer.String(GoogleId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
                if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsResult : public PlayFabBaseModel
        {
            AZStd::vector<GooglePlayFabIdPair> Data; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGoogleIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGoogleIDsResult(const GetPlayFabIDsFromGoogleIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGoogleIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGoogleIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGoogleIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(GooglePlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> KongregateIDs; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromKongregateIDsRequest() :
                PlayFabBaseModel(),
                KongregateIDs()
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const GetPlayFabIDsFromKongregateIDsRequest& src) :
                PlayFabBaseModel(),
                KongregateIDs(src.KongregateIDs)
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromKongregateIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromKongregateIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("KongregateIDs");
                writer.StartArray();
                for (auto iter = KongregateIDs.begin(); iter != KongregateIDs.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateIDs_member = obj.FindMember("KongregateIDs");
                if (KongregateIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KongregateIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KongregateIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct KongregatePlayFabIdPair : public PlayFabBaseModel
        {
            AZStd::string KongregateId;
            AZStd::string PlayFabId;

            KongregatePlayFabIdPair() :
                PlayFabBaseModel(),
                KongregateId(),
                PlayFabId()
            {}

            KongregatePlayFabIdPair(const KongregatePlayFabIdPair& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                PlayFabId(src.PlayFabId)
            {}

            KongregatePlayFabIdPair(const rapidjson::Value& obj) : KongregatePlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~KongregatePlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (KongregateId.length() > 0) {
                    writer.String("KongregateId");
                    writer.String(KongregateId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsResult : public PlayFabBaseModel
        {
            AZStd::vector<KongregatePlayFabIdPair> Data; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromKongregateIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromKongregateIDsResult(const GetPlayFabIDsFromKongregateIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromKongregateIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromKongregateIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromKongregateIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(KongregatePlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromSteamIDsRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> SteamStringIDs; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabBaseModel(),
                SteamStringIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabBaseModel(),
                SteamStringIDs(src.SteamStringIDs)
            {}

            GetPlayFabIDsFromSteamIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!SteamStringIDs.empty()) {
                    writer.String("SteamStringIDs");
                    writer.StartArray();
                    for (auto iter = SteamStringIDs.begin(); iter != SteamStringIDs.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamStringIDs_member = obj.FindMember("SteamStringIDs");
                if (SteamStringIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = SteamStringIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        SteamStringIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct SteamPlayFabIdPair : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string SteamStringId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                SteamStringId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SteamStringId(src.SteamStringId)
            {}

            SteamPlayFabIdPair(const rapidjson::Value& obj) : SteamPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~SteamPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (SteamStringId.length() > 0) {
                    writer.String("SteamStringId");
                    writer.String(SteamStringId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator SteamStringId_member = obj.FindMember("SteamStringId");
                if (SteamStringId_member != obj.MemberEnd() && !SteamStringId_member->value.IsNull()) SteamStringId = SteamStringId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromSteamIDsResult : public PlayFabBaseModel
        {
            AZStd::vector<SteamPlayFabIdPair> Data; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromSteamIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromSteamIDsResult(const GetPlayFabIDsFromSteamIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromSteamIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(SteamPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> TwitchIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromTwitchIDsRequest() :
                PlayFabBaseModel(),
                TwitchIds()
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const GetPlayFabIDsFromTwitchIDsRequest& src) :
                PlayFabBaseModel(),
                TwitchIds(src.TwitchIds)
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromTwitchIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromTwitchIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("TwitchIds");
                writer.StartArray();
                for (auto iter = TwitchIds.begin(); iter != TwitchIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TwitchIds_member = obj.FindMember("TwitchIds");
                if (TwitchIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = TwitchIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        TwitchIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct TwitchPlayFabIdPair : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string TwitchId;

            TwitchPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                TwitchId()
            {}

            TwitchPlayFabIdPair(const TwitchPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TwitchId(src.TwitchId)
            {}

            TwitchPlayFabIdPair(const rapidjson::Value& obj) : TwitchPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~TwitchPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (TwitchId.length() > 0) {
                    writer.String("TwitchId");
                    writer.String(TwitchId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator TwitchId_member = obj.FindMember("TwitchId");
                if (TwitchId_member != obj.MemberEnd() && !TwitchId_member->value.IsNull()) TwitchId = TwitchId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsResult : public PlayFabBaseModel
        {
            AZStd::vector<TwitchPlayFabIdPair> Data; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromTwitchIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromTwitchIDsResult(const GetPlayFabIDsFromTwitchIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromTwitchIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromTwitchIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromTwitchIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(TwitchPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPublisherDataRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> Keys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPublisherDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetPublisherDataRequest(const GetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetPublisherDataRequest(const rapidjson::Value& obj) : GetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Keys");
                writer.StartArray();
                for (auto iter = Keys.begin(); iter != Keys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPublisherDataResult : public PlayFabBaseModel
        {
            std::map<AZStd::string, AZStd::string> Data;

            GetPublisherDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPublisherDataResult(const GetPublisherDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPublisherDataResult(const rapidjson::Value& obj) : GetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct GetPurchaseRequest : public PlayFabBaseModel
        {
            AZStd::string OrderId;

            GetPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId()
            {}

            GetPurchaseRequest(const GetPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId)
            {}

            GetPurchaseRequest(const rapidjson::Value& obj) : GetPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~GetPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();

                return true;
            }
        };

        struct GetPurchaseResult : public PlayFabBaseModel
        {
            AZStd::string OrderId;
            AZStd::string PaymentProvider;
            time_t PurchaseDate;
            AZStd::string TransactionId;
            AZStd::string TransactionStatus;

            GetPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                PaymentProvider(),
                PurchaseDate(0),
                TransactionId(),
                TransactionStatus()
            {}

            GetPurchaseResult(const GetPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                PaymentProvider(src.PaymentProvider),
                PurchaseDate(src.PurchaseDate),
                TransactionId(src.TransactionId),
                TransactionStatus(src.TransactionStatus)
            {}

            GetPurchaseResult(const rapidjson::Value& obj) : GetPurchaseResult()
            {
                readFromValue(obj);
            }

            ~GetPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                if (PaymentProvider.length() > 0) {
                    writer.String("PaymentProvider");
                    writer.String(PaymentProvider.c_str());
                }
                writer.String("PurchaseDate");
                writeDatetime(PurchaseDate, writer);
                if (TransactionId.length() > 0) {
                    writer.String("TransactionId");
                    writer.String(TransactionId.c_str());
                }
                if (TransactionStatus.length() > 0) {
                    writer.String("TransactionStatus");
                    writer.String(TransactionStatus.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator PaymentProvider_member = obj.FindMember("PaymentProvider");
                if (PaymentProvider_member != obj.MemberEnd() && !PaymentProvider_member->value.IsNull()) PaymentProvider = PaymentProvider_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
                const Value::ConstMemberIterator TransactionId_member = obj.FindMember("TransactionId");
                if (TransactionId_member != obj.MemberEnd() && !TransactionId_member->value.IsNull()) TransactionId = TransactionId_member->value.GetString();
                const Value::ConstMemberIterator TransactionStatus_member = obj.FindMember("TransactionStatus");
                if (TransactionStatus_member != obj.MemberEnd() && !TransactionStatus_member->value.IsNull()) TransactionStatus = TransactionStatus_member->value.GetString();

                return true;
            }
        };

        struct GetSharedGroupDataRequest : public PlayFabBaseModel
        {
            OptionalBool GetMembers;
            AZStd::vector<AZStd::string> Keys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string SharedGroupId;

            GetSharedGroupDataRequest() :
                PlayFabBaseModel(),
                GetMembers(),
                Keys(),
                SharedGroupId()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                GetMembers(src.GetMembers),
                Keys(src.Keys),
                SharedGroupId(src.SharedGroupId)
            {}

            GetSharedGroupDataRequest(const rapidjson::Value& obj) : GetSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (GetMembers.notNull()) {
                    writer.String("GetMembers");
                    writer.Bool(GetMembers);
                }
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GetMembers_member = obj.FindMember("GetMembers");
                if (GetMembers_member != obj.MemberEnd() && !GetMembers_member->value.IsNull()) GetMembers = GetMembers_member->value.GetBool();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct SharedGroupDataRecord : public PlayFabBaseModel
        {
            time_t LastUpdated;
            AZStd::string LastUpdatedBy;
            Boxed<UserDataPermission> Permission;
            AZStd::string Value;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(0),
                LastUpdatedBy(),
                Permission(),
                Value()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                LastUpdatedBy(src.LastUpdatedBy),
                Permission(src.Permission),
                Value(src.Value)
            {}

            SharedGroupDataRecord(const rapidjson::Value& obj) : SharedGroupDataRecord()
            {
                readFromValue(obj);
            }

            ~SharedGroupDataRecord()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("LastUpdated");
                writeDatetime(LastUpdated, writer);
                if (LastUpdatedBy.length() > 0) {
                    writer.String("LastUpdatedBy");
                    writer.String(LastUpdatedBy.c_str());
                }
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                if (Value.length() > 0) {
                    writer.String("Value");
                    writer.String(Value.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
                if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
                const Value::ConstMemberIterator LastUpdatedBy_member = obj.FindMember("LastUpdatedBy");
                if (LastUpdatedBy_member != obj.MemberEnd() && !LastUpdatedBy_member->value.IsNull()) LastUpdatedBy = LastUpdatedBy_member->value.GetString();
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct GetSharedGroupDataResult : public PlayFabBaseModel
        {
            std::map<AZStd::string, SharedGroupDataRecord> Data;
            AZStd::vector<AZStd::string> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetSharedGroupDataResult() :
                PlayFabBaseModel(),
                Data(),
                Members()
            {}

            GetSharedGroupDataResult(const GetSharedGroupDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Members(src.Members)
            {}

            GetSharedGroupDataResult(const rapidjson::Value& obj) : GetSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (!Members.empty()) {
                    writer.String("Members");
                    writer.StartArray();
                    for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = SharedGroupDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetStoreItemsRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string StoreId;

            GetStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId()
            {}

            GetStoreItemsRequest(const GetStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            GetStoreItemsRequest(const rapidjson::Value& obj) : GetStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("StoreId");
                writer.String(StoreId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();

                return true;
            }
        };

        struct StoreMarketingModel : public PlayFabBaseModel
        {
            AZStd::string Description;
            AZStd::string DisplayName;
            MultitypeVar Metadata;

            StoreMarketingModel() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                Metadata()
            {}

            StoreMarketingModel(const StoreMarketingModel& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                Metadata(src.Metadata)
            {}

            StoreMarketingModel(const rapidjson::Value& obj) : StoreMarketingModel()
            {
                readFromValue(obj);
            }

            ~StoreMarketingModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (Metadata.notNull()) {
                    writer.String("Metadata");
                    Metadata.writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
                if (Metadata_member != obj.MemberEnd() && !Metadata_member->value.IsNull()) Metadata = MultitypeVar(Metadata_member->value);

                return true;
            }
        };

        enum SourceType
        {
            SourceTypeAdmin,
            SourceTypeBackEnd,
            SourceTypeGameClient,
            SourceTypeGameServer,
            SourceTypePartner
        };

        inline void writeSourceTypeEnumJSON(SourceType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case SourceTypeAdmin: writer.String("Admin"); break;
            case SourceTypeBackEnd: writer.String("BackEnd"); break;
            case SourceTypeGameClient: writer.String("GameClient"); break;
            case SourceTypeGameServer: writer.String("GameServer"); break;
            case SourceTypePartner: writer.String("Partner"); break;

            }
        }

        inline SourceType readSourceTypeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<SourceType>(obj.GetInt());

            static std::map<const char *, SourceType, PlayFabClientSdk::StringCompare> _SourceTypeMap;
            if (_SourceTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _SourceTypeMap["Admin"] = SourceTypeAdmin;
                _SourceTypeMap["BackEnd"] = SourceTypeBackEnd;
                _SourceTypeMap["GameClient"] = SourceTypeGameClient;
                _SourceTypeMap["GameServer"] = SourceTypeGameServer;
                _SourceTypeMap["Partner"] = SourceTypePartner;

            }

            auto output = _SourceTypeMap.find(obj.GetString());
            if (output != _SourceTypeMap.end())
                return output->second;

            return SourceTypeAdmin; // Basically critical fail
        }

        struct StoreItem : public PlayFabBaseModel
        {
            MultitypeVar CustomData;
            OptionalUint32 DisplayPosition;
            AZStd::string ItemId;
            std::map<AZStd::string, Uint32> RealCurrencyPrices;
            std::map<AZStd::string, Uint32> VirtualCurrencyPrices;

            StoreItem() :
                PlayFabBaseModel(),
                CustomData(),
                DisplayPosition(),
                ItemId(),
                RealCurrencyPrices(),
                VirtualCurrencyPrices()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                CustomData(src.CustomData),
                DisplayPosition(src.DisplayPosition),
                ItemId(src.ItemId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            StoreItem(const rapidjson::Value& obj) : StoreItem()
            {
                readFromValue(obj);
            }

            ~StoreItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CustomData.notNull()) {
                    writer.String("CustomData");
                    CustomData.writeJSON(writer);
                }
                if (DisplayPosition.notNull()) {
                    writer.String("DisplayPosition");
                    writer.Uint(DisplayPosition);
                }
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyPrices.empty()) {
                    writer.String("VirtualCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = MultitypeVar(CustomData_member->value);
                const Value::ConstMemberIterator DisplayPosition_member = obj.FindMember("DisplayPosition");
                if (DisplayPosition_member != obj.MemberEnd() && !DisplayPosition_member->value.IsNull()) DisplayPosition = DisplayPosition_member->value.GetUint();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
                if (RealCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
                if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct GetStoreItemsResult : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            StoreMarketingModel* MarketingData;
            Boxed<SourceType> Source;
            AZStd::vector<StoreItem> Store; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string StoreId;

            GetStoreItemsResult() :
                PlayFabBaseModel(),
                CatalogVersion(),
                MarketingData(nullptr),
                Source(),
                Store(),
                StoreId()
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                MarketingData(src.MarketingData ? new StoreMarketingModel(*src.MarketingData) : nullptr),
                Source(src.Source),
                Store(src.Store),
                StoreId(src.StoreId)
            {}

            GetStoreItemsResult(const rapidjson::Value& obj) : GetStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsResult()
            {
                if (MarketingData != nullptr) delete MarketingData;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (MarketingData != nullptr) {
                    writer.String("MarketingData");
                    MarketingData->writeJSON(writer);
                }
                if (Source.notNull()) {
                    writer.String("Source");
                    writeSourceTypeEnumJSON(Source, writer);
                }
                if (!Store.empty()) {
                    writer.String("Store");
                    writer.StartArray();
                    for (auto iter = Store.begin(); iter != Store.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (StoreId.length() > 0) {
                    writer.String("StoreId");
                    writer.String(StoreId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator MarketingData_member = obj.FindMember("MarketingData");
                if (MarketingData_member != obj.MemberEnd() && !MarketingData_member->value.IsNull()) MarketingData = new StoreMarketingModel(MarketingData_member->value);
                const Value::ConstMemberIterator Source_member = obj.FindMember("Source");
                if (Source_member != obj.MemberEnd() && !Source_member->value.IsNull()) Source = readSourceTypeFromValue(Source_member->value);
                const Value::ConstMemberIterator Store_member = obj.FindMember("Store");
                if (Store_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Store_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Store.push_back(StoreItem(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();

                return true;
            }
        };

        struct GetTimeRequest : public PlayFabBaseModel
        {

            GetTimeRequest() :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const GetTimeRequest& src) :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const rapidjson::Value& obj) : GetTimeRequest()
            {
                readFromValue(obj);
            }

            ~GetTimeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetTimeResult : public PlayFabBaseModel
        {
            time_t Time;

            GetTimeResult() :
                PlayFabBaseModel(),
                Time(0)
            {}

            GetTimeResult(const GetTimeResult& src) :
                PlayFabBaseModel(),
                Time(src.Time)
            {}

            GetTimeResult(const rapidjson::Value& obj) : GetTimeResult()
            {
                readFromValue(obj);
            }

            ~GetTimeResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Time");
                writeDatetime(Time, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Time_member = obj.FindMember("Time");
                if (Time_member != obj.MemberEnd() && !Time_member->value.IsNull()) Time = readDatetime(Time_member->value);

                return true;
            }
        };

        struct GetTitleDataRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> Keys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetTitleDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetTitleDataRequest(const rapidjson::Value& obj) : GetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetTitleDataResult : public PlayFabBaseModel
        {
            std::map<AZStd::string, AZStd::string> Data;

            GetTitleDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetTitleDataResult(const GetTitleDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetTitleDataResult(const rapidjson::Value& obj) : GetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~GetTitleDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct GetTitleNewsRequest : public PlayFabBaseModel
        {
            OptionalInt32 Count;

            GetTitleNewsRequest() :
                PlayFabBaseModel(),
                Count()
            {}

            GetTitleNewsRequest(const GetTitleNewsRequest& src) :
                PlayFabBaseModel(),
                Count(src.Count)
            {}

            GetTitleNewsRequest(const rapidjson::Value& obj) : GetTitleNewsRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Count.notNull()) {
                    writer.String("Count");
                    writer.Int(Count);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Count_member = obj.FindMember("Count");
                if (Count_member != obj.MemberEnd() && !Count_member->value.IsNull()) Count = Count_member->value.GetInt();

                return true;
            }
        };

        struct TitleNewsItem : public PlayFabBaseModel
        {
            AZStd::string Body;
            AZStd::string NewsId;
            time_t Timestamp;
            AZStd::string Title;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Body(),
                NewsId(),
                Timestamp(0),
                Title()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                NewsId(src.NewsId),
                Timestamp(src.Timestamp),
                Title(src.Title)
            {}

            TitleNewsItem(const rapidjson::Value& obj) : TitleNewsItem()
            {
                readFromValue(obj);
            }

            ~TitleNewsItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Body.length() > 0) {
                    writer.String("Body");
                    writer.String(Body.c_str());
                }
                if (NewsId.length() > 0) {
                    writer.String("NewsId");
                    writer.String(NewsId.c_str());
                }
                writer.String("Timestamp");
                writeDatetime(Timestamp, writer);
                if (Title.length() > 0) {
                    writer.String("Title");
                    writer.String(Title.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();
                const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
                if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
                if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();

                return true;
            }
        };

        struct GetTitleNewsResult : public PlayFabBaseModel
        {
            AZStd::vector<TitleNewsItem> News; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetTitleNewsResult() :
                PlayFabBaseModel(),
                News()
            {}

            GetTitleNewsResult(const GetTitleNewsResult& src) :
                PlayFabBaseModel(),
                News(src.News)
            {}

            GetTitleNewsResult(const rapidjson::Value& obj) : GetTitleNewsResult()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!News.empty()) {
                    writer.String("News");
                    writer.StartArray();
                    for (auto iter = News.begin(); iter != News.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator News_member = obj.FindMember("News");
                if (News_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = News_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        News.push_back(TitleNewsItem(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetTitlePublicKeyRequest : public PlayFabBaseModel
        {
            AZStd::string TitleId;
            AZStd::string TitleSharedSecret;

            GetTitlePublicKeyRequest() :
                PlayFabBaseModel(),
                TitleId(),
                TitleSharedSecret()
            {}

            GetTitlePublicKeyRequest(const GetTitlePublicKeyRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                TitleSharedSecret(src.TitleSharedSecret)
            {}

            GetTitlePublicKeyRequest(const rapidjson::Value& obj) : GetTitlePublicKeyRequest()
            {
                readFromValue(obj);
            }

            ~GetTitlePublicKeyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.String("TitleSharedSecret");
                writer.String(TitleSharedSecret.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator TitleSharedSecret_member = obj.FindMember("TitleSharedSecret");
                if (TitleSharedSecret_member != obj.MemberEnd() && !TitleSharedSecret_member->value.IsNull()) TitleSharedSecret = TitleSharedSecret_member->value.GetString();

                return true;
            }
        };

        struct GetTitlePublicKeyResult : public PlayFabBaseModel
        {
            AZStd::string RSAPublicKey;

            GetTitlePublicKeyResult() :
                PlayFabBaseModel(),
                RSAPublicKey()
            {}

            GetTitlePublicKeyResult(const GetTitlePublicKeyResult& src) :
                PlayFabBaseModel(),
                RSAPublicKey(src.RSAPublicKey)
            {}

            GetTitlePublicKeyResult(const rapidjson::Value& obj) : GetTitlePublicKeyResult()
            {
                readFromValue(obj);
            }

            ~GetTitlePublicKeyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (RSAPublicKey.length() > 0) {
                    writer.String("RSAPublicKey");
                    writer.String(RSAPublicKey.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator RSAPublicKey_member = obj.FindMember("RSAPublicKey");
                if (RSAPublicKey_member != obj.MemberEnd() && !RSAPublicKey_member->value.IsNull()) RSAPublicKey = RSAPublicKey_member->value.GetString();

                return true;
            }
        };

        struct GetTradeStatusRequest : public PlayFabBaseModel
        {
            AZStd::string OfferingPlayerId;
            AZStd::string TradeId;

            GetTradeStatusRequest() :
                PlayFabBaseModel(),
                OfferingPlayerId(),
                TradeId()
            {}

            GetTradeStatusRequest(const GetTradeStatusRequest& src) :
                PlayFabBaseModel(),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            GetTradeStatusRequest(const rapidjson::Value& obj) : GetTradeStatusRequest()
            {
                readFromValue(obj);
            }

            ~GetTradeStatusRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("OfferingPlayerId");
                writer.String(OfferingPlayerId.c_str());
                writer.String("TradeId");
                writer.String(TradeId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
                if (OfferingPlayerId_member != obj.MemberEnd() && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

                return true;
            }
        };

        struct GetTradeStatusResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            GetTradeStatusResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            GetTradeStatusResponse(const GetTradeStatusResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            GetTradeStatusResponse(const rapidjson::Value& obj) : GetTradeStatusResponse()
            {
                readFromValue(obj);
            }

            ~GetTradeStatusResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct GetUserDataRequest : public PlayFabBaseModel
        {
            OptionalUint32 IfChangedFromDataVersion;
            AZStd::vector<AZStd::string> Keys; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string PlayFabId;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
            {}

            GetUserDataRequest(const rapidjson::Value& obj) : GetUserDataRequest()
            {
                readFromValue(obj);
            }

            ~GetUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (IfChangedFromDataVersion.notNull()) {
                    writer.String("IfChangedFromDataVersion");
                    writer.Uint(IfChangedFromDataVersion);
                }
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
                if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetUserDataResult : public PlayFabBaseModel
        {
            std::map<AZStd::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetUserDataResult() :
                PlayFabBaseModel(),
                Data(),
                DataVersion(0)
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            GetUserDataResult(const rapidjson::Value& obj) : GetUserDataResult()
            {
                readFromValue(obj);
            }

            ~GetUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct GetUserInventoryRequest : public PlayFabBaseModel
        {

            GetUserInventoryRequest() :
                PlayFabBaseModel()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel()
            {}

            GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            AZStd::vector<ItemInstance> Inventory; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, Int32> VirtualCurrency;
            std::map<AZStd::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetUserInventoryResult(const rapidjson::Value& obj) : GetUserInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Inventory.empty()) {
                    writer.String("Inventory");
                    writer.StartArray();
                    for (auto iter = Inventory.begin(); iter != Inventory.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyRechargeTimes.empty()) {
                    writer.String("VirtualCurrencyRechargeTimes");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
                if (Inventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Inventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Inventory.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
                if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
                    }
                }

                return true;
            }
        };

        struct GetWindowsHelloChallengeRequest : public PlayFabBaseModel
        {
            AZStd::string PublicKeyHint;
            AZStd::string TitleId;

            GetWindowsHelloChallengeRequest() :
                PlayFabBaseModel(),
                PublicKeyHint(),
                TitleId()
            {}

            GetWindowsHelloChallengeRequest(const GetWindowsHelloChallengeRequest& src) :
                PlayFabBaseModel(),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            GetWindowsHelloChallengeRequest(const rapidjson::Value& obj) : GetWindowsHelloChallengeRequest()
            {
                readFromValue(obj);
            }

            ~GetWindowsHelloChallengeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("PublicKeyHint");
                writer.String(PublicKeyHint.c_str());
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PublicKeyHint_member = obj.FindMember("PublicKeyHint");
                if (PublicKeyHint_member != obj.MemberEnd() && !PublicKeyHint_member->value.IsNull()) PublicKeyHint = PublicKeyHint_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct GetWindowsHelloChallengeResponse : public PlayFabBaseModel
        {
            AZStd::string Challenge;

            GetWindowsHelloChallengeResponse() :
                PlayFabBaseModel(),
                Challenge()
            {}

            GetWindowsHelloChallengeResponse(const GetWindowsHelloChallengeResponse& src) :
                PlayFabBaseModel(),
                Challenge(src.Challenge)
            {}

            GetWindowsHelloChallengeResponse(const rapidjson::Value& obj) : GetWindowsHelloChallengeResponse()
            {
                readFromValue(obj);
            }

            ~GetWindowsHelloChallengeResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Challenge.length() > 0) {
                    writer.String("Challenge");
                    writer.String(Challenge.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Challenge_member = obj.FindMember("Challenge");
                if (Challenge_member != obj.MemberEnd() && !Challenge_member->value.IsNull()) Challenge = Challenge_member->value.GetString();

                return true;
            }
        };

        struct GrantCharacterToUserRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CharacterName;
            AZStd::string ItemId;

            GrantCharacterToUserRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterName(),
                ItemId()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterName(src.CharacterName),
                ItemId(src.ItemId)
            {}

            GrantCharacterToUserRequest(const rapidjson::Value& obj) : GrantCharacterToUserRequest()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("CharacterName");
                writer.String(CharacterName.c_str());
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();

                return true;
            }
        };

        struct GrantCharacterToUserResult : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            AZStd::string CharacterType;
            bool Result;

            GrantCharacterToUserResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                Result(false)
            {}

            GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                Result(src.Result)
            {}

            GrantCharacterToUserResult(const rapidjson::Value& obj) : GrantCharacterToUserResult()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                writer.String("Result");
                writer.Bool(Result);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
                if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();

                return true;
            }
        };

        struct ItemPurchaseRequest : public PlayFabBaseModel
        {
            AZStd::string Annotation;
            AZStd::string ItemId;
            Uint32 Quantity;
            AZStd::vector<AZStd::string> UpgradeFromItems; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ItemPurchaseRequest() :
                PlayFabBaseModel(),
                Annotation(),
                ItemId(),
                Quantity(0),
                UpgradeFromItems()
            {}

            ItemPurchaseRequest(const ItemPurchaseRequest& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                ItemId(src.ItemId),
                Quantity(src.Quantity),
                UpgradeFromItems(src.UpgradeFromItems)
            {}

            ItemPurchaseRequest(const rapidjson::Value& obj) : ItemPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ItemPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Annotation.length() > 0) {
                    writer.String("Annotation");
                    writer.String(Annotation.c_str());
                }
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                writer.String("Quantity");
                writer.Uint(Quantity);
                if (!UpgradeFromItems.empty()) {
                    writer.String("UpgradeFromItems");
                    writer.StartArray();
                    for (auto iter = UpgradeFromItems.begin(); iter != UpgradeFromItems.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator Quantity_member = obj.FindMember("Quantity");
                if (Quantity_member != obj.MemberEnd() && !Quantity_member->value.IsNull()) Quantity = Quantity_member->value.GetUint();
                const Value::ConstMemberIterator UpgradeFromItems_member = obj.FindMember("UpgradeFromItems");
                if (UpgradeFromItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UpgradeFromItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UpgradeFromItems.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct LinkAndroidDeviceIDRequest : public PlayFabBaseModel
        {
            AZStd::string AndroidDevice;
            AZStd::string AndroidDeviceId;
            OptionalBool ForceLink;
            AZStd::string OS;

            LinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDevice(),
                AndroidDeviceId(),
                ForceLink(),
                OS()
            {}

            LinkAndroidDeviceIDRequest(const LinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                ForceLink(src.ForceLink),
                OS(src.OS)
            {}

            LinkAndroidDeviceIDRequest(const rapidjson::Value& obj) : LinkAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkAndroidDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AndroidDevice.length() > 0) {
                    writer.String("AndroidDevice");
                    writer.String(AndroidDevice.c_str());
                }
                writer.String("AndroidDeviceId");
                writer.String(AndroidDeviceId.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDevice_member = obj.FindMember("AndroidDevice");
                if (AndroidDevice_member != obj.MemberEnd() && !AndroidDevice_member->value.IsNull()) AndroidDevice = AndroidDevice_member->value.GetString();
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();

                return true;
            }
        };

        struct LinkAndroidDeviceIDResult : public PlayFabBaseModel
        {

            LinkAndroidDeviceIDResult() :
                PlayFabBaseModel()
            {}

            LinkAndroidDeviceIDResult(const LinkAndroidDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkAndroidDeviceIDResult(const rapidjson::Value& obj) : LinkAndroidDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~LinkAndroidDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkCustomIDRequest : public PlayFabBaseModel
        {
            AZStd::string CustomId;
            OptionalBool ForceLink;

            LinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId(),
                ForceLink()
            {}

            LinkCustomIDRequest(const LinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId),
                ForceLink(src.ForceLink)
            {}

            LinkCustomIDRequest(const rapidjson::Value& obj) : LinkCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkCustomIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CustomId");
                writer.String(CustomId.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkCustomIDResult : public PlayFabBaseModel
        {

            LinkCustomIDResult() :
                PlayFabBaseModel()
            {}

            LinkCustomIDResult(const LinkCustomIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkCustomIDResult(const rapidjson::Value& obj) : LinkCustomIDResult()
            {
                readFromValue(obj);
            }

            ~LinkCustomIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkFacebookAccountRequest : public PlayFabBaseModel
        {
            AZStd::string AccessToken;
            OptionalBool ForceLink;

            LinkFacebookAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                ForceLink()
            {}

            LinkFacebookAccountRequest(const LinkFacebookAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            LinkFacebookAccountRequest(const rapidjson::Value& obj) : LinkFacebookAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkFacebookAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("AccessToken");
                writer.String(AccessToken.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkFacebookAccountResult : public PlayFabBaseModel
        {

            LinkFacebookAccountResult() :
                PlayFabBaseModel()
            {}

            LinkFacebookAccountResult(const LinkFacebookAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkFacebookAccountResult(const rapidjson::Value& obj) : LinkFacebookAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkFacebookAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkGameCenterAccountRequest : public PlayFabBaseModel
        {
            OptionalBool ForceLink;
            AZStd::string GameCenterId;

            LinkGameCenterAccountRequest() :
                PlayFabBaseModel(),
                ForceLink(),
                GameCenterId()
            {}

            LinkGameCenterAccountRequest(const LinkGameCenterAccountRequest& src) :
                PlayFabBaseModel(),
                ForceLink(src.ForceLink),
                GameCenterId(src.GameCenterId)
            {}

            LinkGameCenterAccountRequest(const rapidjson::Value& obj) : LinkGameCenterAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkGameCenterAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.String("GameCenterId");
                writer.String(GameCenterId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

                return true;
            }
        };

        struct LinkGameCenterAccountResult : public PlayFabBaseModel
        {

            LinkGameCenterAccountResult() :
                PlayFabBaseModel()
            {}

            LinkGameCenterAccountResult(const LinkGameCenterAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkGameCenterAccountResult(const rapidjson::Value& obj) : LinkGameCenterAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkGameCenterAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkGoogleAccountRequest : public PlayFabBaseModel
        {
            OptionalBool ForceLink;
            AZStd::string ServerAuthCode;

            LinkGoogleAccountRequest() :
                PlayFabBaseModel(),
                ForceLink(),
                ServerAuthCode()
            {}

            LinkGoogleAccountRequest(const LinkGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                ForceLink(src.ForceLink),
                ServerAuthCode(src.ServerAuthCode)
            {}

            LinkGoogleAccountRequest(const rapidjson::Value& obj) : LinkGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkGoogleAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                if (ServerAuthCode.length() > 0) {
                    writer.String("ServerAuthCode");
                    writer.String(ServerAuthCode.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
                const Value::ConstMemberIterator ServerAuthCode_member = obj.FindMember("ServerAuthCode");
                if (ServerAuthCode_member != obj.MemberEnd() && !ServerAuthCode_member->value.IsNull()) ServerAuthCode = ServerAuthCode_member->value.GetString();

                return true;
            }
        };

        struct LinkGoogleAccountResult : public PlayFabBaseModel
        {

            LinkGoogleAccountResult() :
                PlayFabBaseModel()
            {}

            LinkGoogleAccountResult(const LinkGoogleAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkGoogleAccountResult(const rapidjson::Value& obj) : LinkGoogleAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkGoogleAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkIOSDeviceIDRequest : public PlayFabBaseModel
        {
            AZStd::string DeviceId;
            AZStd::string DeviceModel;
            OptionalBool ForceLink;
            AZStd::string OS;

            LinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                DeviceId(),
                DeviceModel(),
                ForceLink(),
                OS()
            {}

            LinkIOSDeviceIDRequest(const LinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                ForceLink(src.ForceLink),
                OS(src.OS)
            {}

            LinkIOSDeviceIDRequest(const rapidjson::Value& obj) : LinkIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkIOSDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("DeviceId");
                writer.String(DeviceId.c_str());
                if (DeviceModel.length() > 0) {
                    writer.String("DeviceModel");
                    writer.String(DeviceModel.c_str());
                }
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceId_member = obj.FindMember("DeviceId");
                if (DeviceId_member != obj.MemberEnd() && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();
                const Value::ConstMemberIterator DeviceModel_member = obj.FindMember("DeviceModel");
                if (DeviceModel_member != obj.MemberEnd() && !DeviceModel_member->value.IsNull()) DeviceModel = DeviceModel_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();

                return true;
            }
        };

        struct LinkIOSDeviceIDResult : public PlayFabBaseModel
        {

            LinkIOSDeviceIDResult() :
                PlayFabBaseModel()
            {}

            LinkIOSDeviceIDResult(const LinkIOSDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkIOSDeviceIDResult(const rapidjson::Value& obj) : LinkIOSDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~LinkIOSDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkKongregateAccountRequest : public PlayFabBaseModel
        {
            AZStd::string AuthTicket;
            OptionalBool ForceLink;
            AZStd::string KongregateId;

            LinkKongregateAccountRequest() :
                PlayFabBaseModel(),
                AuthTicket(),
                ForceLink(),
                KongregateId()
            {}

            LinkKongregateAccountRequest(const LinkKongregateAccountRequest& src) :
                PlayFabBaseModel(),
                AuthTicket(src.AuthTicket),
                ForceLink(src.ForceLink),
                KongregateId(src.KongregateId)
            {}

            LinkKongregateAccountRequest(const rapidjson::Value& obj) : LinkKongregateAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkKongregateAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("AuthTicket");
                writer.String(AuthTicket.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.String("KongregateId");
                writer.String(KongregateId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AuthTicket_member = obj.FindMember("AuthTicket");
                if (AuthTicket_member != obj.MemberEnd() && !AuthTicket_member->value.IsNull()) AuthTicket = AuthTicket_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();

                return true;
            }
        };

        struct LinkKongregateAccountResult : public PlayFabBaseModel
        {

            LinkKongregateAccountResult() :
                PlayFabBaseModel()
            {}

            LinkKongregateAccountResult(const LinkKongregateAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkKongregateAccountResult(const rapidjson::Value& obj) : LinkKongregateAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkKongregateAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkSteamAccountRequest : public PlayFabBaseModel
        {
            OptionalBool ForceLink;
            AZStd::string SteamTicket;

            LinkSteamAccountRequest() :
                PlayFabBaseModel(),
                ForceLink(),
                SteamTicket()
            {}

            LinkSteamAccountRequest(const LinkSteamAccountRequest& src) :
                PlayFabBaseModel(),
                ForceLink(src.ForceLink),
                SteamTicket(src.SteamTicket)
            {}

            LinkSteamAccountRequest(const rapidjson::Value& obj) : LinkSteamAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkSteamAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.String("SteamTicket");
                writer.String(SteamTicket.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
                const Value::ConstMemberIterator SteamTicket_member = obj.FindMember("SteamTicket");
                if (SteamTicket_member != obj.MemberEnd() && !SteamTicket_member->value.IsNull()) SteamTicket = SteamTicket_member->value.GetString();

                return true;
            }
        };

        struct LinkSteamAccountResult : public PlayFabBaseModel
        {

            LinkSteamAccountResult() :
                PlayFabBaseModel()
            {}

            LinkSteamAccountResult(const LinkSteamAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkSteamAccountResult(const rapidjson::Value& obj) : LinkSteamAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkSteamAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkTwitchAccountRequest : public PlayFabBaseModel
        {
            AZStd::string AccessToken;
            OptionalBool ForceLink;

            LinkTwitchAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                ForceLink()
            {}

            LinkTwitchAccountRequest(const LinkTwitchAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            LinkTwitchAccountRequest(const rapidjson::Value& obj) : LinkTwitchAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkTwitchAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("AccessToken");
                writer.String(AccessToken.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkTwitchAccountResult : public PlayFabBaseModel
        {

            LinkTwitchAccountResult() :
                PlayFabBaseModel()
            {}

            LinkTwitchAccountResult(const LinkTwitchAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkTwitchAccountResult(const rapidjson::Value& obj) : LinkTwitchAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkTwitchAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkWindowsHelloAccountRequest : public PlayFabBaseModel
        {
            AZStd::string DeviceName;
            OptionalBool ForceLink;
            AZStd::string PublicKey;
            AZStd::string UserName;

            LinkWindowsHelloAccountRequest() :
                PlayFabBaseModel(),
                DeviceName(),
                ForceLink(),
                PublicKey(),
                UserName()
            {}

            LinkWindowsHelloAccountRequest(const LinkWindowsHelloAccountRequest& src) :
                PlayFabBaseModel(),
                DeviceName(src.DeviceName),
                ForceLink(src.ForceLink),
                PublicKey(src.PublicKey),
                UserName(src.UserName)
            {}

            LinkWindowsHelloAccountRequest(const rapidjson::Value& obj) : LinkWindowsHelloAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkWindowsHelloAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DeviceName.length() > 0) {
                    writer.String("DeviceName");
                    writer.String(DeviceName.c_str());
                }
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.String("PublicKey");
                writer.String(PublicKey.c_str());
                writer.String("UserName");
                writer.String(UserName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceName_member = obj.FindMember("DeviceName");
                if (DeviceName_member != obj.MemberEnd() && !DeviceName_member->value.IsNull()) DeviceName = DeviceName_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
                const Value::ConstMemberIterator PublicKey_member = obj.FindMember("PublicKey");
                if (PublicKey_member != obj.MemberEnd() && !PublicKey_member->value.IsNull()) PublicKey = PublicKey_member->value.GetString();
                const Value::ConstMemberIterator UserName_member = obj.FindMember("UserName");
                if (UserName_member != obj.MemberEnd() && !UserName_member->value.IsNull()) UserName = UserName_member->value.GetString();

                return true;
            }
        };

        struct LinkWindowsHelloAccountResponse : public PlayFabBaseModel
        {

            LinkWindowsHelloAccountResponse() :
                PlayFabBaseModel()
            {}

            LinkWindowsHelloAccountResponse(const LinkWindowsHelloAccountResponse& src) :
                PlayFabBaseModel()
            {}

            LinkWindowsHelloAccountResponse(const rapidjson::Value& obj) : LinkWindowsHelloAccountResponse()
            {
                readFromValue(obj);
            }

            ~LinkWindowsHelloAccountResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ListUsersCharactersRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;

            ListUsersCharactersRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ListUsersCharactersRequest(const ListUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            ListUsersCharactersRequest(const rapidjson::Value& obj) : ListUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct ListUsersCharactersResult : public PlayFabBaseModel
        {
            AZStd::vector<CharacterResult> Characters; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListUsersCharactersResult() :
                PlayFabBaseModel(),
                Characters()
            {}

            ListUsersCharactersResult(const ListUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Characters(src.Characters)
            {}

            ListUsersCharactersResult(const rapidjson::Value& obj) : ListUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Characters.empty()) {
                    writer.String("Characters");
                    writer.StartArray();
                    for (auto iter = Characters.begin(); iter != Characters.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Characters_member = obj.FindMember("Characters");
                if (Characters_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Characters_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Characters.push_back(CharacterResult(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UserSettings : public PlayFabBaseModel
        {
            bool GatherDeviceInfo;
            bool NeedsAttribution;

            UserSettings() :
                PlayFabBaseModel(),
                GatherDeviceInfo(false),
                NeedsAttribution(false)
            {}

            UserSettings(const UserSettings& src) :
                PlayFabBaseModel(),
                GatherDeviceInfo(src.GatherDeviceInfo),
                NeedsAttribution(src.NeedsAttribution)
            {}

            UserSettings(const rapidjson::Value& obj) : UserSettings()
            {
                readFromValue(obj);
            }

            ~UserSettings()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GatherDeviceInfo");
                writer.Bool(GatherDeviceInfo);
                writer.String("NeedsAttribution");
                writer.Bool(NeedsAttribution);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GatherDeviceInfo_member = obj.FindMember("GatherDeviceInfo");
                if (GatherDeviceInfo_member != obj.MemberEnd() && !GatherDeviceInfo_member->value.IsNull()) GatherDeviceInfo = GatherDeviceInfo_member->value.GetBool();
                const Value::ConstMemberIterator NeedsAttribution_member = obj.FindMember("NeedsAttribution");
                if (NeedsAttribution_member != obj.MemberEnd() && !NeedsAttribution_member->value.IsNull()) NeedsAttribution = NeedsAttribution_member->value.GetBool();

                return true;
            }
        };

        struct LoginResult : public PlayFabBaseModel
        {
            EntityTokenResponse* EntityToken;
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;
            OptionalTime LastLoginTime;
            bool NewlyCreated;
            AZStd::string PlayFabId;
            AZStd::string SessionTicket;
            UserSettings* SettingsForUser;

            LoginResult() :
                PlayFabBaseModel(),
                EntityToken(nullptr),
                InfoResultPayload(nullptr),
                LastLoginTime(),
                NewlyCreated(false),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser(nullptr)
            {}

            LoginResult(const LoginResult& src) :
                PlayFabBaseModel(),
                EntityToken(src.EntityToken ? new EntityTokenResponse(*src.EntityToken) : nullptr),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : nullptr),
                LastLoginTime(src.LastLoginTime),
                NewlyCreated(src.NewlyCreated),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : nullptr)
            {}

            LoginResult(const rapidjson::Value& obj) : LoginResult()
            {
                readFromValue(obj);
            }

            ~LoginResult()
            {
                if (EntityToken != nullptr) delete EntityToken;
                if (InfoResultPayload != nullptr) delete InfoResultPayload;
                if (SettingsForUser != nullptr) delete SettingsForUser;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (EntityToken != nullptr) {
                    writer.String("EntityToken");
                    EntityToken->writeJSON(writer);
                }
                if (InfoResultPayload != nullptr) {
                    writer.String("InfoResultPayload");
                    InfoResultPayload->writeJSON(writer);
                }
                if (LastLoginTime.notNull()) {
                    writer.String("LastLoginTime");
                    writeDatetime(LastLoginTime, writer);
                }
                writer.String("NewlyCreated");
                writer.Bool(NewlyCreated);
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (SessionTicket.length() > 0) {
                    writer.String("SessionTicket");
                    writer.String(SessionTicket.c_str());
                }
                if (SettingsForUser != nullptr) {
                    writer.String("SettingsForUser");
                    SettingsForUser->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EntityToken_member = obj.FindMember("EntityToken");
                if (EntityToken_member != obj.MemberEnd() && !EntityToken_member->value.IsNull()) EntityToken = new EntityTokenResponse(EntityToken_member->value);
                const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
                if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);
                const Value::ConstMemberIterator LastLoginTime_member = obj.FindMember("LastLoginTime");
                if (LastLoginTime_member != obj.MemberEnd() && !LastLoginTime_member->value.IsNull()) LastLoginTime = readDatetime(LastLoginTime_member->value);
                const Value::ConstMemberIterator NewlyCreated_member = obj.FindMember("NewlyCreated");
                if (NewlyCreated_member != obj.MemberEnd() && !NewlyCreated_member->value.IsNull()) NewlyCreated = NewlyCreated_member->value.GetBool();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
                if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
                const Value::ConstMemberIterator SettingsForUser_member = obj.FindMember("SettingsForUser");
                if (SettingsForUser_member != obj.MemberEnd() && !SettingsForUser_member->value.IsNull()) SettingsForUser = new UserSettings(SettingsForUser_member->value);

                return true;
            }
        };

        struct LoginWithAndroidDeviceIDRequest : public PlayFabBaseModel
        {
            AZStd::string AndroidDevice;
            AZStd::string AndroidDeviceId;
            OptionalBool CreateAccount;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string OS;
            AZStd::string PlayerSecret;
            AZStd::string TitleId;

            LoginWithAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDevice(),
                AndroidDeviceId(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithAndroidDeviceIDRequest(const LoginWithAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithAndroidDeviceIDRequest(const rapidjson::Value& obj) : LoginWithAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithAndroidDeviceIDRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AndroidDevice.length() > 0) {
                    writer.String("AndroidDevice");
                    writer.String(AndroidDevice.c_str());
                }
                if (AndroidDeviceId.length() > 0) {
                    writer.String("AndroidDeviceId");
                    writer.String(AndroidDeviceId.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDevice_member = obj.FindMember("AndroidDevice");
                if (AndroidDevice_member != obj.MemberEnd() && !AndroidDevice_member->value.IsNull()) AndroidDevice = AndroidDevice_member->value.GetString();
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithCustomIDRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            AZStd::string CustomId;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerSecret;
            AZStd::string TitleId;

            LoginWithCustomIDRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomId(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithCustomIDRequest(const LoginWithCustomIDRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomId(src.CustomId),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithCustomIDRequest(const rapidjson::Value& obj) : LoginWithCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithCustomIDRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (CustomId.length() > 0) {
                    writer.String("CustomId");
                    writer.String(CustomId.c_str());
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithEmailAddressRequest : public PlayFabBaseModel
        {
            AZStd::string Email;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string Password;
            AZStd::string TitleId;

            LoginWithEmailAddressRequest() :
                PlayFabBaseModel(),
                Email(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                Password(),
                TitleId()
            {}

            LoginWithEmailAddressRequest(const LoginWithEmailAddressRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                TitleId(src.TitleId)
            {}

            LoginWithEmailAddressRequest(const rapidjson::Value& obj) : LoginWithEmailAddressRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithEmailAddressRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Email");
                writer.String(Email.c_str());
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                writer.String("Password");
                writer.String(Password.c_str());
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithFacebookRequest : public PlayFabBaseModel
        {
            AZStd::string AccessToken;
            OptionalBool CreateAccount;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerSecret;
            AZStd::string TitleId;

            LoginWithFacebookRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithFacebookRequest(const LoginWithFacebookRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithFacebookRequest(const rapidjson::Value& obj) : LoginWithFacebookRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithFacebookRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("AccessToken");
                writer.String(AccessToken.c_str());
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithGameCenterRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerId;
            AZStd::string PlayerSecret;
            AZStd::string TitleId;

            LoginWithGameCenterRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PlayerId(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithGameCenterRequest(const LoginWithGameCenterRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerId(src.PlayerId),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithGameCenterRequest(const rapidjson::Value& obj) : LoginWithGameCenterRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithGameCenterRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerId.length() > 0) {
                    writer.String("PlayerId");
                    writer.String(PlayerId.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
                if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithGoogleAccountRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerSecret;
            AZStd::string ServerAuthCode;
            AZStd::string TitleId;

            LoginWithGoogleAccountRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                ServerAuthCode(),
                TitleId()
            {}

            LoginWithGoogleAccountRequest(const LoginWithGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                ServerAuthCode(src.ServerAuthCode),
                TitleId(src.TitleId)
            {}

            LoginWithGoogleAccountRequest(const rapidjson::Value& obj) : LoginWithGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithGoogleAccountRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (ServerAuthCode.length() > 0) {
                    writer.String("ServerAuthCode");
                    writer.String(ServerAuthCode.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator ServerAuthCode_member = obj.FindMember("ServerAuthCode");
                if (ServerAuthCode_member != obj.MemberEnd() && !ServerAuthCode_member->value.IsNull()) ServerAuthCode = ServerAuthCode_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithIOSDeviceIDRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            AZStd::string DeviceId;
            AZStd::string DeviceModel;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string OS;
            AZStd::string PlayerSecret;
            AZStd::string TitleId;

            LoginWithIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                DeviceId(),
                DeviceModel(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithIOSDeviceIDRequest(const LoginWithIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithIOSDeviceIDRequest(const rapidjson::Value& obj) : LoginWithIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithIOSDeviceIDRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (DeviceId.length() > 0) {
                    writer.String("DeviceId");
                    writer.String(DeviceId.c_str());
                }
                if (DeviceModel.length() > 0) {
                    writer.String("DeviceModel");
                    writer.String(DeviceModel.c_str());
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator DeviceId_member = obj.FindMember("DeviceId");
                if (DeviceId_member != obj.MemberEnd() && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();
                const Value::ConstMemberIterator DeviceModel_member = obj.FindMember("DeviceModel");
                if (DeviceModel_member != obj.MemberEnd() && !DeviceModel_member->value.IsNull()) DeviceModel = DeviceModel_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithKongregateRequest : public PlayFabBaseModel
        {
            AZStd::string AuthTicket;
            OptionalBool CreateAccount;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            AZStd::string KongregateId;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerSecret;
            AZStd::string TitleId;

            LoginWithKongregateRequest() :
                PlayFabBaseModel(),
                AuthTicket(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                KongregateId(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithKongregateRequest(const LoginWithKongregateRequest& src) :
                PlayFabBaseModel(),
                AuthTicket(src.AuthTicket),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                KongregateId(src.KongregateId),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithKongregateRequest(const rapidjson::Value& obj) : LoginWithKongregateRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithKongregateRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AuthTicket.length() > 0) {
                    writer.String("AuthTicket");
                    writer.String(AuthTicket.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (KongregateId.length() > 0) {
                    writer.String("KongregateId");
                    writer.String(KongregateId.c_str());
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AuthTicket_member = obj.FindMember("AuthTicket");
                if (AuthTicket_member != obj.MemberEnd() && !AuthTicket_member->value.IsNull()) AuthTicket = AuthTicket_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithPlayFabRequest : public PlayFabBaseModel
        {
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string Password;
            AZStd::string TitleId;
            AZStd::string Username;

            LoginWithPlayFabRequest() :
                PlayFabBaseModel(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                Password(),
                TitleId(),
                Username()
            {}

            LoginWithPlayFabRequest(const LoginWithPlayFabRequest& src) :
                PlayFabBaseModel(),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                TitleId(src.TitleId),
                Username(src.Username)
            {}

            LoginWithPlayFabRequest(const rapidjson::Value& obj) : LoginWithPlayFabRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithPlayFabRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                writer.String("Password");
                writer.String(Password.c_str());
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.String("Username");
                writer.String(Username.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct LoginWithSteamRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerSecret;
            AZStd::string SteamTicket;
            AZStd::string TitleId;

            LoginWithSteamRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                SteamTicket(),
                TitleId()
            {}

            LoginWithSteamRequest(const LoginWithSteamRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                SteamTicket(src.SteamTicket),
                TitleId(src.TitleId)
            {}

            LoginWithSteamRequest(const rapidjson::Value& obj) : LoginWithSteamRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithSteamRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (SteamTicket.length() > 0) {
                    writer.String("SteamTicket");
                    writer.String(SteamTicket.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator SteamTicket_member = obj.FindMember("SteamTicket");
                if (SteamTicket_member != obj.MemberEnd() && !SteamTicket_member->value.IsNull()) SteamTicket = SteamTicket_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithTwitchRequest : public PlayFabBaseModel
        {
            AZStd::string AccessToken;
            OptionalBool CreateAccount;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerSecret;
            AZStd::string TitleId;

            LoginWithTwitchRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithTwitchRequest(const LoginWithTwitchRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithTwitchRequest(const rapidjson::Value& obj) : LoginWithTwitchRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithTwitchRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AccessToken.length() > 0) {
                    writer.String("AccessToken");
                    writer.String(AccessToken.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct LoginWithWindowsHelloRequest : public PlayFabBaseModel
        {
            AZStd::string ChallengeSignature;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PublicKeyHint;
            AZStd::string TitleId;

            LoginWithWindowsHelloRequest() :
                PlayFabBaseModel(),
                ChallengeSignature(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PublicKeyHint(),
                TitleId()
            {}

            LoginWithWindowsHelloRequest(const LoginWithWindowsHelloRequest& src) :
                PlayFabBaseModel(),
                ChallengeSignature(src.ChallengeSignature),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            LoginWithWindowsHelloRequest(const rapidjson::Value& obj) : LoginWithWindowsHelloRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithWindowsHelloRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ChallengeSignature");
                writer.String(ChallengeSignature.c_str());
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                writer.String("PublicKeyHint");
                writer.String(PublicKeyHint.c_str());
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ChallengeSignature_member = obj.FindMember("ChallengeSignature");
                if (ChallengeSignature_member != obj.MemberEnd() && !ChallengeSignature_member->value.IsNull()) ChallengeSignature = ChallengeSignature_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PublicKeyHint_member = obj.FindMember("PublicKeyHint");
                if (PublicKeyHint_member != obj.MemberEnd() && !PublicKeyHint_member->value.IsNull()) PublicKeyHint = PublicKeyHint_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct MatchmakeRequest : public PlayFabBaseModel
        {
            AZStd::string BuildVersion;
            AZStd::string CharacterId;
            AZStd::string GameMode;
            AZStd::string LobbyId;
            Boxed<Region> pfRegion;
            OptionalBool StartNewIfNoneFound;
            AZStd::string StatisticName;
            CollectionFilter* TagFilter;

            MatchmakeRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                CharacterId(),
                GameMode(),
                LobbyId(),
                pfRegion(),
                StartNewIfNoneFound(),
                StatisticName(),
                TagFilter(nullptr)
            {}

            MatchmakeRequest(const MatchmakeRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                pfRegion(src.pfRegion),
                StartNewIfNoneFound(src.StartNewIfNoneFound),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter ? new CollectionFilter(*src.TagFilter) : nullptr)
            {}

            MatchmakeRequest(const rapidjson::Value& obj) : MatchmakeRequest()
            {
                readFromValue(obj);
            }

            ~MatchmakeRequest()
            {
                if (TagFilter != nullptr) delete TagFilter;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (BuildVersion.length() > 0) {
                    writer.String("BuildVersion");
                    writer.String(BuildVersion.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (GameMode.length() > 0) {
                    writer.String("GameMode");
                    writer.String(GameMode.c_str());
                }
                if (LobbyId.length() > 0) {
                    writer.String("LobbyId");
                    writer.String(LobbyId.c_str());
                }
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                if (StartNewIfNoneFound.notNull()) {
                    writer.String("StartNewIfNoneFound");
                    writer.Bool(StartNewIfNoneFound);
                }
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                if (TagFilter != nullptr) {
                    writer.String("TagFilter");
                    TagFilter->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator StartNewIfNoneFound_member = obj.FindMember("StartNewIfNoneFound");
                if (StartNewIfNoneFound_member != obj.MemberEnd() && !StartNewIfNoneFound_member->value.IsNull()) StartNewIfNoneFound = StartNewIfNoneFound_member->value.GetBool();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator TagFilter_member = obj.FindMember("TagFilter");
                if (TagFilter_member != obj.MemberEnd() && !TagFilter_member->value.IsNull()) TagFilter = new CollectionFilter(TagFilter_member->value);

                return true;
            }
        };

        enum MatchmakeStatus
        {
            MatchmakeStatusComplete,
            MatchmakeStatusWaiting,
            MatchmakeStatusGameNotFound,
            MatchmakeStatusNoAvailableSlots,
            MatchmakeStatusSessionClosed
        };

        inline void writeMatchmakeStatusEnumJSON(MatchmakeStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case MatchmakeStatusComplete: writer.String("Complete"); break;
            case MatchmakeStatusWaiting: writer.String("Waiting"); break;
            case MatchmakeStatusGameNotFound: writer.String("GameNotFound"); break;
            case MatchmakeStatusNoAvailableSlots: writer.String("NoAvailableSlots"); break;
            case MatchmakeStatusSessionClosed: writer.String("SessionClosed"); break;

            }
        }

        inline MatchmakeStatus readMatchmakeStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<MatchmakeStatus>(obj.GetInt());

            static std::map<const char *, MatchmakeStatus, PlayFabClientSdk::StringCompare> _MatchmakeStatusMap;
            if (_MatchmakeStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _MatchmakeStatusMap["Complete"] = MatchmakeStatusComplete;
                _MatchmakeStatusMap["Waiting"] = MatchmakeStatusWaiting;
                _MatchmakeStatusMap["GameNotFound"] = MatchmakeStatusGameNotFound;
                _MatchmakeStatusMap["NoAvailableSlots"] = MatchmakeStatusNoAvailableSlots;
                _MatchmakeStatusMap["SessionClosed"] = MatchmakeStatusSessionClosed;

            }

            auto output = _MatchmakeStatusMap.find(obj.GetString());
            if (output != _MatchmakeStatusMap.end())
                return output->second;

            return MatchmakeStatusComplete; // Basically critical fail
        }

        struct MatchmakeResult : public PlayFabBaseModel
        {
            AZStd::string Expires;
            AZStd::string LobbyID;
            OptionalInt32 PollWaitTimeMS;
            AZStd::string ServerHostname;
            AZStd::string ServerIPV6Address;
            OptionalInt32 ServerPort;
            Boxed<MatchmakeStatus> Status;
            AZStd::string Ticket;

            MatchmakeResult() :
                PlayFabBaseModel(),
                Expires(),
                LobbyID(),
                PollWaitTimeMS(),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort(),
                Status(),
                Ticket()
            {}

            MatchmakeResult(const MatchmakeResult& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                PollWaitTimeMS(src.PollWaitTimeMS),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                Status(src.Status),
                Ticket(src.Ticket)
            {}

            MatchmakeResult(const rapidjson::Value& obj) : MatchmakeResult()
            {
                readFromValue(obj);
            }

            ~MatchmakeResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Expires.length() > 0) {
                    writer.String("Expires");
                    writer.String(Expires.c_str());
                }
                if (LobbyID.length() > 0) {
                    writer.String("LobbyID");
                    writer.String(LobbyID.c_str());
                }
                if (PollWaitTimeMS.notNull()) {
                    writer.String("PollWaitTimeMS");
                    writer.Int(PollWaitTimeMS);
                }
                if (ServerHostname.length() > 0) {
                    writer.String("ServerHostname");
                    writer.String(ServerHostname.c_str());
                }
                if (ServerIPV6Address.length() > 0) {
                    writer.String("ServerIPV6Address");
                    writer.String(ServerIPV6Address.c_str());
                }
                if (ServerPort.notNull()) {
                    writer.String("ServerPort");
                    writer.Int(ServerPort);
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeMatchmakeStatusEnumJSON(Status, writer);
                }
                if (Ticket.length() > 0) {
                    writer.String("Ticket");
                    writer.String(Ticket.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = Expires_member->value.GetString();
                const Value::ConstMemberIterator LobbyID_member = obj.FindMember("LobbyID");
                if (LobbyID_member != obj.MemberEnd() && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
                const Value::ConstMemberIterator PollWaitTimeMS_member = obj.FindMember("PollWaitTimeMS");
                if (PollWaitTimeMS_member != obj.MemberEnd() && !PollWaitTimeMS_member->value.IsNull()) PollWaitTimeMS = PollWaitTimeMS_member->value.GetInt();
                const Value::ConstMemberIterator ServerHostname_member = obj.FindMember("ServerHostname");
                if (ServerHostname_member != obj.MemberEnd() && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
                const Value::ConstMemberIterator ServerIPV6Address_member = obj.FindMember("ServerIPV6Address");
                if (ServerIPV6Address_member != obj.MemberEnd() && !ServerIPV6Address_member->value.IsNull()) ServerIPV6Address = ServerIPV6Address_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readMatchmakeStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator Ticket_member = obj.FindMember("Ticket");
                if (Ticket_member != obj.MemberEnd() && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();

                return true;
            }
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabBaseModel
        {
            Int32 Balance;
            Int32 BalanceChange;
            AZStd::string PlayFabId;
            AZStd::string VirtualCurrency;

            ModifyUserVirtualCurrencyResult() :
                PlayFabBaseModel(),
                Balance(0),
                BalanceChange(0),
                PlayFabId(),
                VirtualCurrency()
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                Balance(src.Balance),
                BalanceChange(src.BalanceChange),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ModifyUserVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyUserVirtualCurrencyResult()
            {
                readFromValue(obj);
            }

            ~ModifyUserVirtualCurrencyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Balance");
                writer.Int(Balance);
                writer.String("BalanceChange");
                writer.Int(BalanceChange);
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (VirtualCurrency.length() > 0) {
                    writer.String("VirtualCurrency");
                    writer.String(VirtualCurrency.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
                if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();
                const Value::ConstMemberIterator BalanceChange_member = obj.FindMember("BalanceChange");
                if (BalanceChange_member != obj.MemberEnd() && !BalanceChange_member->value.IsNull()) BalanceChange = BalanceChange_member->value.GetInt();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

                return true;
            }
        };

        struct NameIdentifier : public PlayFabBaseModel
        {
            AZStd::string Id;
            AZStd::string Name;

            NameIdentifier() :
                PlayFabBaseModel(),
                Id(),
                Name()
            {}

            NameIdentifier(const NameIdentifier& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name)
            {}

            NameIdentifier(const rapidjson::Value& obj) : NameIdentifier()
            {
                readFromValue(obj);
            }

            ~NameIdentifier()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Id.length() > 0) {
                    writer.String("Id");
                    writer.String(Id.c_str());
                }
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

                return true;
            }
        };

        struct OpenTradeRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> AllowedPlayerIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> OfferedInventoryInstanceIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> RequestedCatalogItemIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            OpenTradeRequest() :
                PlayFabBaseModel(),
                AllowedPlayerIds(),
                OfferedInventoryInstanceIds(),
                RequestedCatalogItemIds()
            {}

            OpenTradeRequest(const OpenTradeRequest& src) :
                PlayFabBaseModel(),
                AllowedPlayerIds(src.AllowedPlayerIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds)
            {}

            OpenTradeRequest(const rapidjson::Value& obj) : OpenTradeRequest()
            {
                readFromValue(obj);
            }

            ~OpenTradeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!AllowedPlayerIds.empty()) {
                    writer.String("AllowedPlayerIds");
                    writer.StartArray();
                    for (auto iter = AllowedPlayerIds.begin(); iter != AllowedPlayerIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!OfferedInventoryInstanceIds.empty()) {
                    writer.String("OfferedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = OfferedInventoryInstanceIds.begin(); iter != OfferedInventoryInstanceIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!RequestedCatalogItemIds.empty()) {
                    writer.String("RequestedCatalogItemIds");
                    writer.StartArray();
                    for (auto iter = RequestedCatalogItemIds.begin(); iter != RequestedCatalogItemIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AllowedPlayerIds_member = obj.FindMember("AllowedPlayerIds");
                if (AllowedPlayerIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AllowedPlayerIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AllowedPlayerIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator OfferedInventoryInstanceIds_member = obj.FindMember("OfferedInventoryInstanceIds");
                if (OfferedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OfferedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OfferedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator RequestedCatalogItemIds_member = obj.FindMember("RequestedCatalogItemIds");
                if (RequestedCatalogItemIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = RequestedCatalogItemIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        RequestedCatalogItemIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct OpenTradeResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            OpenTradeResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            OpenTradeResponse(const OpenTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            OpenTradeResponse(const rapidjson::Value& obj) : OpenTradeResponse()
            {
                readFromValue(obj);
            }

            ~OpenTradeResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct PayForPurchaseRequest : public PlayFabBaseModel
        {
            AZStd::string Currency;
            AZStd::string OrderId;
            AZStd::string ProviderName;
            AZStd::string ProviderTransactionId;

            PayForPurchaseRequest() :
                PlayFabBaseModel(),
                Currency(),
                OrderId(),
                ProviderName(),
                ProviderTransactionId()
            {}

            PayForPurchaseRequest(const PayForPurchaseRequest& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                OrderId(src.OrderId),
                ProviderName(src.ProviderName),
                ProviderTransactionId(src.ProviderTransactionId)
            {}

            PayForPurchaseRequest(const rapidjson::Value& obj) : PayForPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~PayForPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Currency");
                writer.String(Currency.c_str());
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                writer.String("ProviderName");
                writer.String(ProviderName.c_str());
                if (ProviderTransactionId.length() > 0) {
                    writer.String("ProviderTransactionId");
                    writer.String(ProviderTransactionId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator ProviderName_member = obj.FindMember("ProviderName");
                if (ProviderName_member != obj.MemberEnd() && !ProviderName_member->value.IsNull()) ProviderName = ProviderName_member->value.GetString();
                const Value::ConstMemberIterator ProviderTransactionId_member = obj.FindMember("ProviderTransactionId");
                if (ProviderTransactionId_member != obj.MemberEnd() && !ProviderTransactionId_member->value.IsNull()) ProviderTransactionId = ProviderTransactionId_member->value.GetString();

                return true;
            }
        };

        enum TransactionStatus
        {
            TransactionStatusCreateCart,
            TransactionStatusInit,
            TransactionStatusApproved,
            TransactionStatusSucceeded,
            TransactionStatusFailedByProvider,
            TransactionStatusDisputePending,
            TransactionStatusRefundPending,
            TransactionStatusRefunded,
            TransactionStatusRefundFailed,
            TransactionStatusChargedBack,
            TransactionStatusFailedByUber,
            TransactionStatusFailedByPlayFab,
            TransactionStatusRevoked,
            TransactionStatusTradePending,
            TransactionStatusTraded,
            TransactionStatusUpgraded,
            TransactionStatusStackPending,
            TransactionStatusStacked,
            TransactionStatusOther,
            TransactionStatusFailed
        };

        inline void writeTransactionStatusEnumJSON(TransactionStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TransactionStatusCreateCart: writer.String("CreateCart"); break;
            case TransactionStatusInit: writer.String("Init"); break;
            case TransactionStatusApproved: writer.String("Approved"); break;
            case TransactionStatusSucceeded: writer.String("Succeeded"); break;
            case TransactionStatusFailedByProvider: writer.String("FailedByProvider"); break;
            case TransactionStatusDisputePending: writer.String("DisputePending"); break;
            case TransactionStatusRefundPending: writer.String("RefundPending"); break;
            case TransactionStatusRefunded: writer.String("Refunded"); break;
            case TransactionStatusRefundFailed: writer.String("RefundFailed"); break;
            case TransactionStatusChargedBack: writer.String("ChargedBack"); break;
            case TransactionStatusFailedByUber: writer.String("FailedByUber"); break;
            case TransactionStatusFailedByPlayFab: writer.String("FailedByPlayFab"); break;
            case TransactionStatusRevoked: writer.String("Revoked"); break;
            case TransactionStatusTradePending: writer.String("TradePending"); break;
            case TransactionStatusTraded: writer.String("Traded"); break;
            case TransactionStatusUpgraded: writer.String("Upgraded"); break;
            case TransactionStatusStackPending: writer.String("StackPending"); break;
            case TransactionStatusStacked: writer.String("Stacked"); break;
            case TransactionStatusOther: writer.String("Other"); break;
            case TransactionStatusFailed: writer.String("Failed"); break;

            }
        }

        inline TransactionStatus readTransactionStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<TransactionStatus>(obj.GetInt());

            static std::map<const char *, TransactionStatus, PlayFabClientSdk::StringCompare> _TransactionStatusMap;
            if (_TransactionStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TransactionStatusMap["CreateCart"] = TransactionStatusCreateCart;
                _TransactionStatusMap["Init"] = TransactionStatusInit;
                _TransactionStatusMap["Approved"] = TransactionStatusApproved;
                _TransactionStatusMap["Succeeded"] = TransactionStatusSucceeded;
                _TransactionStatusMap["FailedByProvider"] = TransactionStatusFailedByProvider;
                _TransactionStatusMap["DisputePending"] = TransactionStatusDisputePending;
                _TransactionStatusMap["RefundPending"] = TransactionStatusRefundPending;
                _TransactionStatusMap["Refunded"] = TransactionStatusRefunded;
                _TransactionStatusMap["RefundFailed"] = TransactionStatusRefundFailed;
                _TransactionStatusMap["ChargedBack"] = TransactionStatusChargedBack;
                _TransactionStatusMap["FailedByUber"] = TransactionStatusFailedByUber;
                _TransactionStatusMap["FailedByPlayFab"] = TransactionStatusFailedByPlayFab;
                _TransactionStatusMap["Revoked"] = TransactionStatusRevoked;
                _TransactionStatusMap["TradePending"] = TransactionStatusTradePending;
                _TransactionStatusMap["Traded"] = TransactionStatusTraded;
                _TransactionStatusMap["Upgraded"] = TransactionStatusUpgraded;
                _TransactionStatusMap["StackPending"] = TransactionStatusStackPending;
                _TransactionStatusMap["Stacked"] = TransactionStatusStacked;
                _TransactionStatusMap["Other"] = TransactionStatusOther;
                _TransactionStatusMap["Failed"] = TransactionStatusFailed;

            }

            auto output = _TransactionStatusMap.find(obj.GetString());
            if (output != _TransactionStatusMap.end())
                return output->second;

            return TransactionStatusCreateCart; // Basically critical fail
        }

        struct PayForPurchaseResult : public PlayFabBaseModel
        {
            Uint32 CreditApplied;
            AZStd::string OrderId;
            AZStd::string ProviderData;
            AZStd::string ProviderToken;
            AZStd::string PurchaseConfirmationPageURL;
            AZStd::string PurchaseCurrency;
            Uint32 PurchasePrice;
            Boxed<TransactionStatus> Status;
            std::map<AZStd::string, Int32> VCAmount;
            std::map<AZStd::string, Int32> VirtualCurrency;

            PayForPurchaseResult() :
                PlayFabBaseModel(),
                CreditApplied(0),
                OrderId(),
                ProviderData(),
                ProviderToken(),
                PurchaseConfirmationPageURL(),
                PurchaseCurrency(),
                PurchasePrice(0),
                Status(),
                VCAmount(),
                VirtualCurrency()
            {}

            PayForPurchaseResult(const PayForPurchaseResult& src) :
                PlayFabBaseModel(),
                CreditApplied(src.CreditApplied),
                OrderId(src.OrderId),
                ProviderData(src.ProviderData),
                ProviderToken(src.ProviderToken),
                PurchaseConfirmationPageURL(src.PurchaseConfirmationPageURL),
                PurchaseCurrency(src.PurchaseCurrency),
                PurchasePrice(src.PurchasePrice),
                Status(src.Status),
                VCAmount(src.VCAmount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            PayForPurchaseResult(const rapidjson::Value& obj) : PayForPurchaseResult()
            {
                readFromValue(obj);
            }

            ~PayForPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CreditApplied");
                writer.Uint(CreditApplied);
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                if (ProviderData.length() > 0) {
                    writer.String("ProviderData");
                    writer.String(ProviderData.c_str());
                }
                if (ProviderToken.length() > 0) {
                    writer.String("ProviderToken");
                    writer.String(ProviderToken.c_str());
                }
                if (PurchaseConfirmationPageURL.length() > 0) {
                    writer.String("PurchaseConfirmationPageURL");
                    writer.String(PurchaseConfirmationPageURL.c_str());
                }
                if (PurchaseCurrency.length() > 0) {
                    writer.String("PurchaseCurrency");
                    writer.String(PurchaseCurrency.c_str());
                }
                writer.String("PurchasePrice");
                writer.Uint(PurchasePrice);
                if (Status.notNull()) {
                    writer.String("Status");
                    writeTransactionStatusEnumJSON(Status, writer);
                }
                if (!VCAmount.empty()) {
                    writer.String("VCAmount");
                    writer.StartObject();
                    for (auto iter = VCAmount.begin(); iter != VCAmount.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CreditApplied_member = obj.FindMember("CreditApplied");
                if (CreditApplied_member != obj.MemberEnd() && !CreditApplied_member->value.IsNull()) CreditApplied = CreditApplied_member->value.GetUint();
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator ProviderData_member = obj.FindMember("ProviderData");
                if (ProviderData_member != obj.MemberEnd() && !ProviderData_member->value.IsNull()) ProviderData = ProviderData_member->value.GetString();
                const Value::ConstMemberIterator ProviderToken_member = obj.FindMember("ProviderToken");
                if (ProviderToken_member != obj.MemberEnd() && !ProviderToken_member->value.IsNull()) ProviderToken = ProviderToken_member->value.GetString();
                const Value::ConstMemberIterator PurchaseConfirmationPageURL_member = obj.FindMember("PurchaseConfirmationPageURL");
                if (PurchaseConfirmationPageURL_member != obj.MemberEnd() && !PurchaseConfirmationPageURL_member->value.IsNull()) PurchaseConfirmationPageURL = PurchaseConfirmationPageURL_member->value.GetString();
                const Value::ConstMemberIterator PurchaseCurrency_member = obj.FindMember("PurchaseCurrency");
                if (PurchaseCurrency_member != obj.MemberEnd() && !PurchaseCurrency_member->value.IsNull()) PurchaseCurrency = PurchaseCurrency_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTransactionStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator VCAmount_member = obj.FindMember("VCAmount");
                if (VCAmount_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VCAmount_member->value.MemberBegin(); iter != VCAmount_member->value.MemberEnd(); ++iter) {
                        VCAmount[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }

                return true;
            }
        };

        struct PaymentOption : public PlayFabBaseModel
        {
            AZStd::string Currency;
            Uint32 Price;
            AZStd::string ProviderName;
            Uint32 StoreCredit;

            PaymentOption() :
                PlayFabBaseModel(),
                Currency(),
                Price(0),
                ProviderName(),
                StoreCredit(0)
            {}

            PaymentOption(const PaymentOption& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                Price(src.Price),
                ProviderName(src.ProviderName),
                StoreCredit(src.StoreCredit)
            {}

            PaymentOption(const rapidjson::Value& obj) : PaymentOption()
            {
                readFromValue(obj);
            }

            ~PaymentOption()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Currency.length() > 0) {
                    writer.String("Currency");
                    writer.String(Currency.c_str());
                }
                writer.String("Price");
                writer.Uint(Price);
                if (ProviderName.length() > 0) {
                    writer.String("ProviderName");
                    writer.String(ProviderName.c_str());
                }
                writer.String("StoreCredit");
                writer.Uint(StoreCredit);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator Price_member = obj.FindMember("Price");
                if (Price_member != obj.MemberEnd() && !Price_member->value.IsNull()) Price = Price_member->value.GetUint();
                const Value::ConstMemberIterator ProviderName_member = obj.FindMember("ProviderName");
                if (ProviderName_member != obj.MemberEnd() && !ProviderName_member->value.IsNull()) ProviderName = ProviderName_member->value.GetString();
                const Value::ConstMemberIterator StoreCredit_member = obj.FindMember("StoreCredit");
                if (StoreCredit_member != obj.MemberEnd() && !StoreCredit_member->value.IsNull()) StoreCredit = StoreCredit_member->value.GetUint();

                return true;
            }
        };

        struct PurchaseItemRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CharacterId;
            AZStd::string ItemId;
            Int32 Price;
            AZStd::string StoreId;
            AZStd::string VirtualCurrency;

            PurchaseItemRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                ItemId(),
                Price(0),
                StoreId(),
                VirtualCurrency()
            {}

            PurchaseItemRequest(const PurchaseItemRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ItemId(src.ItemId),
                Price(src.Price),
                StoreId(src.StoreId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            PurchaseItemRequest(const rapidjson::Value& obj) : PurchaseItemRequest()
            {
                readFromValue(obj);
            }

            ~PurchaseItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                writer.String("Price");
                writer.Int(Price);
                if (StoreId.length() > 0) {
                    writer.String("StoreId");
                    writer.String(StoreId.c_str());
                }
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator Price_member = obj.FindMember("Price");
                if (Price_member != obj.MemberEnd() && !Price_member->value.IsNull()) Price = Price_member->value.GetInt();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

                return true;
            }
        };

        struct PurchaseItemResult : public PlayFabBaseModel
        {
            AZStd::vector<ItemInstance> Items; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            PurchaseItemResult() :
                PlayFabBaseModel(),
                Items()
            {}

            PurchaseItemResult(const PurchaseItemResult& src) :
                PlayFabBaseModel(),
                Items(src.Items)
            {}

            PurchaseItemResult(const rapidjson::Value& obj) : PurchaseItemResult()
            {
                readFromValue(obj);
            }

            ~PurchaseItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Items.empty()) {
                    writer.String("Items");
                    writer.StartArray();
                    for (auto iter = Items.begin(); iter != Items.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Items_member = obj.FindMember("Items");
                if (Items_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Items_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Items.push_back(ItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct RedeemCouponRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CharacterId;
            AZStd::string CouponCode;

            RedeemCouponRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                CouponCode()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CouponCode(src.CouponCode)
            {}

            RedeemCouponRequest(const rapidjson::Value& obj) : RedeemCouponRequest()
            {
                readFromValue(obj);
            }

            ~RedeemCouponRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.String("CouponCode");
                writer.String(CouponCode.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CouponCode_member = obj.FindMember("CouponCode");
                if (CouponCode_member != obj.MemberEnd() && !CouponCode_member->value.IsNull()) CouponCode = CouponCode_member->value.GetString();

                return true;
            }
        };

        struct RedeemCouponResult : public PlayFabBaseModel
        {
            AZStd::vector<ItemInstance> GrantedItems; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            RedeemCouponResult() :
                PlayFabBaseModel(),
                GrantedItems()
            {}

            RedeemCouponResult(const RedeemCouponResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems)
            {}

            RedeemCouponResult(const rapidjson::Value& obj) : RedeemCouponResult()
            {
                readFromValue(obj);
            }

            ~RedeemCouponResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!GrantedItems.empty()) {
                    writer.String("GrantedItems");
                    writer.StartArray();
                    for (auto iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
                if (GrantedItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GrantedItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GrantedItems.push_back(ItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct RegisterForIOSPushNotificationRequest : public PlayFabBaseModel
        {
            AZStd::string ConfirmationMessage;
            AZStd::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;

            RegisterForIOSPushNotificationRequest() :
                PlayFabBaseModel(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            RegisterForIOSPushNotificationRequest(const RegisterForIOSPushNotificationRequest& src) :
                PlayFabBaseModel(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
            {}

            RegisterForIOSPushNotificationRequest(const rapidjson::Value& obj) : RegisterForIOSPushNotificationRequest()
            {
                readFromValue(obj);
            }

            ~RegisterForIOSPushNotificationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ConfirmationMessage.length() > 0) {
                    writer.String("ConfirmationMessage");
                    writer.String(ConfirmationMessage.c_str());
                }
                writer.String("DeviceToken");
                writer.String(DeviceToken.c_str());
                if (SendPushNotificationConfirmation.notNull()) {
                    writer.String("SendPushNotificationConfirmation");
                    writer.Bool(SendPushNotificationConfirmation);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ConfirmationMessage_member = obj.FindMember("ConfirmationMessage");
                if (ConfirmationMessage_member != obj.MemberEnd() && !ConfirmationMessage_member->value.IsNull()) ConfirmationMessage = ConfirmationMessage_member->value.GetString();
                const Value::ConstMemberIterator DeviceToken_member = obj.FindMember("DeviceToken");
                if (DeviceToken_member != obj.MemberEnd() && !DeviceToken_member->value.IsNull()) DeviceToken = DeviceToken_member->value.GetString();
                const Value::ConstMemberIterator SendPushNotificationConfirmation_member = obj.FindMember("SendPushNotificationConfirmation");
                if (SendPushNotificationConfirmation_member != obj.MemberEnd() && !SendPushNotificationConfirmation_member->value.IsNull()) SendPushNotificationConfirmation = SendPushNotificationConfirmation_member->value.GetBool();

                return true;
            }
        };

        struct RegisterForIOSPushNotificationResult : public PlayFabBaseModel
        {

            RegisterForIOSPushNotificationResult() :
                PlayFabBaseModel()
            {}

            RegisterForIOSPushNotificationResult(const RegisterForIOSPushNotificationResult& src) :
                PlayFabBaseModel()
            {}

            RegisterForIOSPushNotificationResult(const rapidjson::Value& obj) : RegisterForIOSPushNotificationResult()
            {
                readFromValue(obj);
            }

            ~RegisterForIOSPushNotificationResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RegisterPlayFabUserRequest : public PlayFabBaseModel
        {
            AZStd::string DisplayName;
            AZStd::string Email;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string Password;
            AZStd::string PlayerSecret;
            OptionalBool RequireBothUsernameAndEmail;
            AZStd::string TitleId;
            AZStd::string Username;

            RegisterPlayFabUserRequest() :
                PlayFabBaseModel(),
                DisplayName(),
                Email(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                Password(),
                PlayerSecret(),
                RequireBothUsernameAndEmail(),
                TitleId(),
                Username()
            {}

            RegisterPlayFabUserRequest(const RegisterPlayFabUserRequest& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Email(src.Email),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                PlayerSecret(src.PlayerSecret),
                RequireBothUsernameAndEmail(src.RequireBothUsernameAndEmail),
                TitleId(src.TitleId),
                Username(src.Username)
            {}

            RegisterPlayFabUserRequest(const rapidjson::Value& obj) : RegisterPlayFabUserRequest()
            {
                readFromValue(obj);
            }

            ~RegisterPlayFabUserRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (Password.length() > 0) {
                    writer.String("Password");
                    writer.String(Password.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (RequireBothUsernameAndEmail.notNull()) {
                    writer.String("RequireBothUsernameAndEmail");
                    writer.Bool(RequireBothUsernameAndEmail);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator RequireBothUsernameAndEmail_member = obj.FindMember("RequireBothUsernameAndEmail");
                if (RequireBothUsernameAndEmail_member != obj.MemberEnd() && !RequireBothUsernameAndEmail_member->value.IsNull()) RequireBothUsernameAndEmail = RequireBothUsernameAndEmail_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct RegisterPlayFabUserResult : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string SessionTicket;
            UserSettings* SettingsForUser;
            AZStd::string Username;

            RegisterPlayFabUserResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser(nullptr),
                Username()
            {}

            RegisterPlayFabUserResult(const RegisterPlayFabUserResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : nullptr),
                Username(src.Username)
            {}

            RegisterPlayFabUserResult(const rapidjson::Value& obj) : RegisterPlayFabUserResult()
            {
                readFromValue(obj);
            }

            ~RegisterPlayFabUserResult()
            {
                if (SettingsForUser != nullptr) delete SettingsForUser;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (SessionTicket.length() > 0) {
                    writer.String("SessionTicket");
                    writer.String(SessionTicket.c_str());
                }
                if (SettingsForUser != nullptr) {
                    writer.String("SettingsForUser");
                    SettingsForUser->writeJSON(writer);
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
                if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
                const Value::ConstMemberIterator SettingsForUser_member = obj.FindMember("SettingsForUser");
                if (SettingsForUser_member != obj.MemberEnd() && !SettingsForUser_member->value.IsNull()) SettingsForUser = new UserSettings(SettingsForUser_member->value);
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct RegisterWithWindowsHelloRequest : public PlayFabBaseModel
        {
            AZStd::string DeviceName;
            AZStd::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalBool LoginTitlePlayerAccountEntity;
            AZStd::string PlayerSecret;
            AZStd::string PublicKey;
            AZStd::string TitleId;
            AZStd::string UserName;

            RegisterWithWindowsHelloRequest() :
                PlayFabBaseModel(),
                DeviceName(),
                EncryptedRequest(),
                InfoRequestParameters(nullptr),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                PublicKey(),
                TitleId(),
                UserName()
            {}

            RegisterWithWindowsHelloRequest(const RegisterWithWindowsHelloRequest& src) :
                PlayFabBaseModel(),
                DeviceName(src.DeviceName),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                PublicKey(src.PublicKey),
                TitleId(src.TitleId),
                UserName(src.UserName)
            {}

            RegisterWithWindowsHelloRequest(const rapidjson::Value& obj) : RegisterWithWindowsHelloRequest()
            {
                readFromValue(obj);
            }

            ~RegisterWithWindowsHelloRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DeviceName.length() > 0) {
                    writer.String("DeviceName");
                    writer.String(DeviceName.c_str());
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                if (LoginTitlePlayerAccountEntity.notNull()) {
                    writer.String("LoginTitlePlayerAccountEntity");
                    writer.Bool(LoginTitlePlayerAccountEntity);
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (PublicKey.length() > 0) {
                    writer.String("PublicKey");
                    writer.String(PublicKey.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (UserName.length() > 0) {
                    writer.String("UserName");
                    writer.String(UserName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceName_member = obj.FindMember("DeviceName");
                if (DeviceName_member != obj.MemberEnd() && !DeviceName_member->value.IsNull()) DeviceName = DeviceName_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator LoginTitlePlayerAccountEntity_member = obj.FindMember("LoginTitlePlayerAccountEntity");
                if (LoginTitlePlayerAccountEntity_member != obj.MemberEnd() && !LoginTitlePlayerAccountEntity_member->value.IsNull()) LoginTitlePlayerAccountEntity = LoginTitlePlayerAccountEntity_member->value.GetBool();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator PublicKey_member = obj.FindMember("PublicKey");
                if (PublicKey_member != obj.MemberEnd() && !PublicKey_member->value.IsNull()) PublicKey = PublicKey_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator UserName_member = obj.FindMember("UserName");
                if (UserName_member != obj.MemberEnd() && !UserName_member->value.IsNull()) UserName = UserName_member->value.GetString();

                return true;
            }
        };

        struct RemoveContactEmailRequest : public PlayFabBaseModel
        {

            RemoveContactEmailRequest() :
                PlayFabBaseModel()
            {}

            RemoveContactEmailRequest(const RemoveContactEmailRequest& src) :
                PlayFabBaseModel()
            {}

            RemoveContactEmailRequest(const rapidjson::Value& obj) : RemoveContactEmailRequest()
            {
                readFromValue(obj);
            }

            ~RemoveContactEmailRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RemoveContactEmailResult : public PlayFabBaseModel
        {

            RemoveContactEmailResult() :
                PlayFabBaseModel()
            {}

            RemoveContactEmailResult(const RemoveContactEmailResult& src) :
                PlayFabBaseModel()
            {}

            RemoveContactEmailResult(const rapidjson::Value& obj) : RemoveContactEmailResult()
            {
                readFromValue(obj);
            }

            ~RemoveContactEmailResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RemoveFriendRequest : public PlayFabBaseModel
        {
            AZStd::string FriendPlayFabId;

            RemoveFriendRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId)
            {}

            RemoveFriendRequest(const rapidjson::Value& obj) : RemoveFriendRequest()
            {
                readFromValue(obj);
            }

            ~RemoveFriendRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("FriendPlayFabId");
                writer.String(FriendPlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();

                return true;
            }
        };

        struct RemoveFriendResult : public PlayFabBaseModel
        {

            RemoveFriendResult() :
                PlayFabBaseModel()
            {}

            RemoveFriendResult(const RemoveFriendResult& src) :
                PlayFabBaseModel()
            {}

            RemoveFriendResult(const rapidjson::Value& obj) : RemoveFriendResult()
            {
                readFromValue(obj);
            }

            ~RemoveFriendResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RemoveGenericIDRequest : public PlayFabBaseModel
        {
            GenericServiceId GenericId;

            RemoveGenericIDRequest() :
                PlayFabBaseModel(),
                GenericId()
            {}

            RemoveGenericIDRequest(const RemoveGenericIDRequest& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId)
            {}

            RemoveGenericIDRequest(const rapidjson::Value& obj) : RemoveGenericIDRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGenericIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("GenericId");
                GenericId.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericId_member = obj.FindMember("GenericId");
                if (GenericId_member != obj.MemberEnd() && !GenericId_member->value.IsNull()) GenericId = GenericServiceId(GenericId_member->value);

                return true;
            }
        };

        struct RemoveGenericIDResult : public PlayFabBaseModel
        {

            RemoveGenericIDResult() :
                PlayFabBaseModel()
            {}

            RemoveGenericIDResult(const RemoveGenericIDResult& src) :
                PlayFabBaseModel()
            {}

            RemoveGenericIDResult(const rapidjson::Value& obj) : RemoveGenericIDResult()
            {
                readFromValue(obj);
            }

            ~RemoveGenericIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabBaseModel
        {
            AZStd::vector<AZStd::string> PlayFabIds; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string SharedGroupId;

            RemoveSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                SharedGroupId()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
            {}

            RemoveSharedGroupMembersRequest(const rapidjson::Value& obj) : RemoveSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("PlayFabIds");
                writer.StartArray();
                for (auto iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
                if (PlayFabIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayFabIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayFabIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct RemoveSharedGroupMembersResult : public PlayFabBaseModel
        {

            RemoveSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const RemoveSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const rapidjson::Value& obj) : RemoveSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ReportPlayerClientRequest : public PlayFabBaseModel
        {
            AZStd::string Comment;
            AZStd::string ReporteeId;

            ReportPlayerClientRequest() :
                PlayFabBaseModel(),
                Comment(),
                ReporteeId()
            {}

            ReportPlayerClientRequest(const ReportPlayerClientRequest& src) :
                PlayFabBaseModel(),
                Comment(src.Comment),
                ReporteeId(src.ReporteeId)
            {}

            ReportPlayerClientRequest(const rapidjson::Value& obj) : ReportPlayerClientRequest()
            {
                readFromValue(obj);
            }

            ~ReportPlayerClientRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                writer.String("ReporteeId");
                writer.String(ReporteeId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator ReporteeId_member = obj.FindMember("ReporteeId");
                if (ReporteeId_member != obj.MemberEnd() && !ReporteeId_member->value.IsNull()) ReporteeId = ReporteeId_member->value.GetString();

                return true;
            }
        };

        struct ReportPlayerClientResult : public PlayFabBaseModel
        {
            Int32 SubmissionsRemaining;

            ReportPlayerClientResult() :
                PlayFabBaseModel(),
                SubmissionsRemaining(0)
            {}

            ReportPlayerClientResult(const ReportPlayerClientResult& src) :
                PlayFabBaseModel(),
                SubmissionsRemaining(src.SubmissionsRemaining)
            {}

            ReportPlayerClientResult(const rapidjson::Value& obj) : ReportPlayerClientResult()
            {
                readFromValue(obj);
            }

            ~ReportPlayerClientResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("SubmissionsRemaining");
                writer.Int(SubmissionsRemaining);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SubmissionsRemaining_member = obj.FindMember("SubmissionsRemaining");
                if (SubmissionsRemaining_member != obj.MemberEnd() && !SubmissionsRemaining_member->value.IsNull()) SubmissionsRemaining = SubmissionsRemaining_member->value.GetInt();

                return true;
            }
        };

        struct RestoreIOSPurchasesRequest : public PlayFabBaseModel
        {
            AZStd::string ReceiptData;

            RestoreIOSPurchasesRequest() :
                PlayFabBaseModel(),
                ReceiptData()
            {}

            RestoreIOSPurchasesRequest(const RestoreIOSPurchasesRequest& src) :
                PlayFabBaseModel(),
                ReceiptData(src.ReceiptData)
            {}

            RestoreIOSPurchasesRequest(const rapidjson::Value& obj) : RestoreIOSPurchasesRequest()
            {
                readFromValue(obj);
            }

            ~RestoreIOSPurchasesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ReceiptData");
                writer.String(ReceiptData.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReceiptData_member = obj.FindMember("ReceiptData");
                if (ReceiptData_member != obj.MemberEnd() && !ReceiptData_member->value.IsNull()) ReceiptData = ReceiptData_member->value.GetString();

                return true;
            }
        };

        struct RestoreIOSPurchasesResult : public PlayFabBaseModel
        {

            RestoreIOSPurchasesResult() :
                PlayFabBaseModel()
            {}

            RestoreIOSPurchasesResult(const RestoreIOSPurchasesResult& src) :
                PlayFabBaseModel()
            {}

            RestoreIOSPurchasesResult(const rapidjson::Value& obj) : RestoreIOSPurchasesResult()
            {
                readFromValue(obj);
            }

            ~RestoreIOSPurchasesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabBaseModel
        {
            AZStd::string Email;
            AZStd::string EmailTemplateId;
            AZStd::string TitleId;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                Email(),
                EmailTemplateId(),
                TitleId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId),
                TitleId(src.TitleId)
            {}

            SendAccountRecoveryEmailRequest(const rapidjson::Value& obj) : SendAccountRecoveryEmailRequest()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Email");
                writer.String(Email.c_str());
                if (EmailTemplateId.length() > 0) {
                    writer.String("EmailTemplateId");
                    writer.String(EmailTemplateId.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator EmailTemplateId_member = obj.FindMember("EmailTemplateId");
                if (EmailTemplateId_member != obj.MemberEnd() && !EmailTemplateId_member->value.IsNull()) EmailTemplateId = EmailTemplateId_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct SendAccountRecoveryEmailResult : public PlayFabBaseModel
        {

            SendAccountRecoveryEmailResult() :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const SendAccountRecoveryEmailResult& src) :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const rapidjson::Value& obj) : SendAccountRecoveryEmailResult()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetFriendTagsRequest : public PlayFabBaseModel
        {
            AZStd::string FriendPlayFabId;
            AZStd::vector<AZStd::string> Tags; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetFriendTagsRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                Tags(src.Tags)
            {}

            SetFriendTagsRequest(const rapidjson::Value& obj) : SetFriendTagsRequest()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("FriendPlayFabId");
                writer.String(FriendPlayFabId.c_str());
                writer.String("Tags");
                writer.StartArray();
                for (auto iter = Tags.begin(); iter != Tags.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct SetFriendTagsResult : public PlayFabBaseModel
        {

            SetFriendTagsResult() :
                PlayFabBaseModel()
            {}

            SetFriendTagsResult(const SetFriendTagsResult& src) :
                PlayFabBaseModel()
            {}

            SetFriendTagsResult(const rapidjson::Value& obj) : SetFriendTagsResult()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetPlayerSecretRequest : public PlayFabBaseModel
        {
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;

            SetPlayerSecretRequest() :
                PlayFabBaseModel(),
                EncryptedRequest(),
                PlayerSecret()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabBaseModel(),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret)
            {}

            SetPlayerSecretRequest(const rapidjson::Value& obj) : SetPlayerSecretRequest()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();

                return true;
            }
        };

        struct SetPlayerSecretResult : public PlayFabBaseModel
        {

            SetPlayerSecretResult() :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const SetPlayerSecretResult& src) :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const rapidjson::Value& obj) : SetPlayerSecretResult()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct StartGameRequest : public PlayFabBaseModel
        {
            AZStd::string BuildVersion;
            AZStd::string CharacterId;
            AZStd::string CustomCommandLineData;
            AZStd::string GameMode;
            Region pfRegion;
            AZStd::string StatisticName;

            StartGameRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                CharacterId(),
                CustomCommandLineData(),
                GameMode(),
                pfRegion(),
                StatisticName()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                CustomCommandLineData(src.CustomCommandLineData),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName)
            {}

            StartGameRequest(const rapidjson::Value& obj) : StartGameRequest()
            {
                readFromValue(obj);
            }

            ~StartGameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("BuildVersion");
                writer.String(BuildVersion.c_str());
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CustomCommandLineData.length() > 0) {
                    writer.String("CustomCommandLineData");
                    writer.String(CustomCommandLineData.c_str());
                }
                writer.String("GameMode");
                writer.String(GameMode.c_str());
                writer.String("Region");
                writeRegionEnumJSON(pfRegion, writer);
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CustomCommandLineData_member = obj.FindMember("CustomCommandLineData");
                if (CustomCommandLineData_member != obj.MemberEnd() && !CustomCommandLineData_member->value.IsNull()) CustomCommandLineData = CustomCommandLineData_member->value.GetString();
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct StartGameResult : public PlayFabBaseModel
        {
            AZStd::string Expires;
            AZStd::string LobbyID;
            AZStd::string Password;
            AZStd::string ServerHostname;
            AZStd::string ServerIPV6Address;
            OptionalInt32 ServerPort;
            AZStd::string Ticket;

            StartGameResult() :
                PlayFabBaseModel(),
                Expires(),
                LobbyID(),
                Password(),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort(),
                Ticket()
            {}

            StartGameResult(const StartGameResult& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                Password(src.Password),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                Ticket(src.Ticket)
            {}

            StartGameResult(const rapidjson::Value& obj) : StartGameResult()
            {
                readFromValue(obj);
            }

            ~StartGameResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Expires.length() > 0) {
                    writer.String("Expires");
                    writer.String(Expires.c_str());
                }
                if (LobbyID.length() > 0) {
                    writer.String("LobbyID");
                    writer.String(LobbyID.c_str());
                }
                if (Password.length() > 0) {
                    writer.String("Password");
                    writer.String(Password.c_str());
                }
                if (ServerHostname.length() > 0) {
                    writer.String("ServerHostname");
                    writer.String(ServerHostname.c_str());
                }
                if (ServerIPV6Address.length() > 0) {
                    writer.String("ServerIPV6Address");
                    writer.String(ServerIPV6Address.c_str());
                }
                if (ServerPort.notNull()) {
                    writer.String("ServerPort");
                    writer.Int(ServerPort);
                }
                if (Ticket.length() > 0) {
                    writer.String("Ticket");
                    writer.String(Ticket.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = Expires_member->value.GetString();
                const Value::ConstMemberIterator LobbyID_member = obj.FindMember("LobbyID");
                if (LobbyID_member != obj.MemberEnd() && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator ServerHostname_member = obj.FindMember("ServerHostname");
                if (ServerHostname_member != obj.MemberEnd() && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
                const Value::ConstMemberIterator ServerIPV6Address_member = obj.FindMember("ServerIPV6Address");
                if (ServerIPV6Address_member != obj.MemberEnd() && !ServerIPV6Address_member->value.IsNull()) ServerIPV6Address = ServerIPV6Address_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();
                const Value::ConstMemberIterator Ticket_member = obj.FindMember("Ticket");
                if (Ticket_member != obj.MemberEnd() && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();

                return true;
            }
        };

        struct StartPurchaseRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::vector<ItemPurchaseRequest> Items; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string StoreId;

            StartPurchaseRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Items(),
                StoreId()
            {}

            StartPurchaseRequest(const StartPurchaseRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Items(src.Items),
                StoreId(src.StoreId)
            {}

            StartPurchaseRequest(const rapidjson::Value& obj) : StartPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~StartPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("Items");
                writer.StartArray();
                for (auto iter = Items.begin(); iter != Items.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                if (StoreId.length() > 0) {
                    writer.String("StoreId");
                    writer.String(StoreId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator Items_member = obj.FindMember("Items");
                if (Items_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Items_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Items.push_back(ItemPurchaseRequest(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();

                return true;
            }
        };

        struct StartPurchaseResult : public PlayFabBaseModel
        {
            AZStd::vector<CartItem> Contents; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string OrderId;
            AZStd::vector<PaymentOption> PaymentOptions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            std::map<AZStd::string, Int32> VirtualCurrencyBalances;

            StartPurchaseResult() :
                PlayFabBaseModel(),
                Contents(),
                OrderId(),
                PaymentOptions(),
                VirtualCurrencyBalances()
            {}

            StartPurchaseResult(const StartPurchaseResult& src) :
                PlayFabBaseModel(),
                Contents(src.Contents),
                OrderId(src.OrderId),
                PaymentOptions(src.PaymentOptions),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            StartPurchaseResult(const rapidjson::Value& obj) : StartPurchaseResult()
            {
                readFromValue(obj);
            }

            ~StartPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Contents.empty()) {
                    writer.String("Contents");
                    writer.StartArray();
                    for (auto iter = Contents.begin(); iter != Contents.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                if (!PaymentOptions.empty()) {
                    writer.String("PaymentOptions");
                    writer.StartArray();
                    for (auto iter = PaymentOptions.begin(); iter != PaymentOptions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrencyBalances.empty()) {
                    writer.String("VirtualCurrencyBalances");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Contents_member = obj.FindMember("Contents");
                if (Contents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Contents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Contents.push_back(CartItem(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator PaymentOptions_member = obj.FindMember("PaymentOptions");
                if (PaymentOptions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PaymentOptions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PaymentOptions.push_back(PaymentOption(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
                if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyBalances_member->value.MemberBegin(); iter != VirtualCurrencyBalances_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyBalances[iter->name.GetString()] = iter->value.GetInt();
                    }
                }

                return true;
            }
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
            AZStd::string StatisticName;
            Int32 Value;
            OptionalUint32 Version;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version()
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticUpdate(const rapidjson::Value& obj) : StatisticUpdate()
            {
                readFromValue(obj);
            }

            ~StatisticUpdate()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("Value");
                writer.Int(Value);
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Uint(Version);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            AZStd::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            SubtractUserVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Amount");
                writer.Int(Amount);
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

                return true;
            }
        };

        struct UnlinkAndroidDeviceIDRequest : public PlayFabBaseModel
        {
            AZStd::string AndroidDeviceId;

            UnlinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UnlinkAndroidDeviceIDRequest(const UnlinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UnlinkAndroidDeviceIDRequest(const rapidjson::Value& obj) : UnlinkAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkAndroidDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AndroidDeviceId.length() > 0) {
                    writer.String("AndroidDeviceId");
                    writer.String(AndroidDeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UnlinkAndroidDeviceIDResult : public PlayFabBaseModel
        {

            UnlinkAndroidDeviceIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkAndroidDeviceIDResult(const UnlinkAndroidDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkAndroidDeviceIDResult(const rapidjson::Value& obj) : UnlinkAndroidDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkAndroidDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkCustomIDRequest : public PlayFabBaseModel
        {
            AZStd::string CustomId;

            UnlinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UnlinkCustomIDRequest(const UnlinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UnlinkCustomIDRequest(const rapidjson::Value& obj) : UnlinkCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkCustomIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CustomId.length() > 0) {
                    writer.String("CustomId");
                    writer.String(CustomId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

                return true;
            }
        };

        struct UnlinkCustomIDResult : public PlayFabBaseModel
        {

            UnlinkCustomIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkCustomIDResult(const UnlinkCustomIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkCustomIDResult(const rapidjson::Value& obj) : UnlinkCustomIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkCustomIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkFacebookAccountRequest : public PlayFabBaseModel
        {

            UnlinkFacebookAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountRequest(const UnlinkFacebookAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountRequest(const rapidjson::Value& obj) : UnlinkFacebookAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkFacebookAccountResult : public PlayFabBaseModel
        {

            UnlinkFacebookAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountResult(const UnlinkFacebookAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountResult(const rapidjson::Value& obj) : UnlinkFacebookAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGameCenterAccountRequest : public PlayFabBaseModel
        {

            UnlinkGameCenterAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountRequest(const UnlinkGameCenterAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountRequest(const rapidjson::Value& obj) : UnlinkGameCenterAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkGameCenterAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGameCenterAccountResult : public PlayFabBaseModel
        {

            UnlinkGameCenterAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountResult(const UnlinkGameCenterAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountResult(const rapidjson::Value& obj) : UnlinkGameCenterAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkGameCenterAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGoogleAccountRequest : public PlayFabBaseModel
        {

            UnlinkGoogleAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountRequest(const UnlinkGoogleAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountRequest(const rapidjson::Value& obj) : UnlinkGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkGoogleAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGoogleAccountResult : public PlayFabBaseModel
        {

            UnlinkGoogleAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountResult(const UnlinkGoogleAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountResult(const rapidjson::Value& obj) : UnlinkGoogleAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkGoogleAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkIOSDeviceIDRequest : public PlayFabBaseModel
        {
            AZStd::string DeviceId;

            UnlinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                DeviceId()
            {}

            UnlinkIOSDeviceIDRequest(const UnlinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                DeviceId(src.DeviceId)
            {}

            UnlinkIOSDeviceIDRequest(const rapidjson::Value& obj) : UnlinkIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkIOSDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DeviceId.length() > 0) {
                    writer.String("DeviceId");
                    writer.String(DeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceId_member = obj.FindMember("DeviceId");
                if (DeviceId_member != obj.MemberEnd() && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();

                return true;
            }
        };

        struct UnlinkIOSDeviceIDResult : public PlayFabBaseModel
        {

            UnlinkIOSDeviceIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkIOSDeviceIDResult(const UnlinkIOSDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkIOSDeviceIDResult(const rapidjson::Value& obj) : UnlinkIOSDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkIOSDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkKongregateAccountRequest : public PlayFabBaseModel
        {

            UnlinkKongregateAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountRequest(const UnlinkKongregateAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountRequest(const rapidjson::Value& obj) : UnlinkKongregateAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkKongregateAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkKongregateAccountResult : public PlayFabBaseModel
        {

            UnlinkKongregateAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountResult(const UnlinkKongregateAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountResult(const rapidjson::Value& obj) : UnlinkKongregateAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkKongregateAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkSteamAccountRequest : public PlayFabBaseModel
        {

            UnlinkSteamAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountRequest(const UnlinkSteamAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountRequest(const rapidjson::Value& obj) : UnlinkSteamAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkSteamAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkSteamAccountResult : public PlayFabBaseModel
        {

            UnlinkSteamAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountResult(const UnlinkSteamAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountResult(const rapidjson::Value& obj) : UnlinkSteamAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkSteamAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkTwitchAccountRequest : public PlayFabBaseModel
        {

            UnlinkTwitchAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountRequest(const UnlinkTwitchAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountRequest(const rapidjson::Value& obj) : UnlinkTwitchAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkTwitchAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkTwitchAccountResult : public PlayFabBaseModel
        {

            UnlinkTwitchAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountResult(const UnlinkTwitchAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountResult(const rapidjson::Value& obj) : UnlinkTwitchAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkTwitchAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkWindowsHelloAccountRequest : public PlayFabBaseModel
        {
            AZStd::string PublicKeyHint;

            UnlinkWindowsHelloAccountRequest() :
                PlayFabBaseModel(),
                PublicKeyHint()
            {}

            UnlinkWindowsHelloAccountRequest(const UnlinkWindowsHelloAccountRequest& src) :
                PlayFabBaseModel(),
                PublicKeyHint(src.PublicKeyHint)
            {}

            UnlinkWindowsHelloAccountRequest(const rapidjson::Value& obj) : UnlinkWindowsHelloAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkWindowsHelloAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("PublicKeyHint");
                writer.String(PublicKeyHint.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PublicKeyHint_member = obj.FindMember("PublicKeyHint");
                if (PublicKeyHint_member != obj.MemberEnd() && !PublicKeyHint_member->value.IsNull()) PublicKeyHint = PublicKeyHint_member->value.GetString();

                return true;
            }
        };

        struct UnlinkWindowsHelloAccountResponse : public PlayFabBaseModel
        {

            UnlinkWindowsHelloAccountResponse() :
                PlayFabBaseModel()
            {}

            UnlinkWindowsHelloAccountResponse(const UnlinkWindowsHelloAccountResponse& src) :
                PlayFabBaseModel()
            {}

            UnlinkWindowsHelloAccountResponse(const rapidjson::Value& obj) : UnlinkWindowsHelloAccountResponse()
            {
                readFromValue(obj);
            }

            ~UnlinkWindowsHelloAccountResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlockContainerInstanceRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CharacterId;
            AZStd::string ContainerItemInstanceId;
            AZStd::string KeyItemInstanceId;

            UnlockContainerInstanceRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemInstanceId(),
                KeyItemInstanceId()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                KeyItemInstanceId(src.KeyItemInstanceId)
            {}

            UnlockContainerInstanceRequest(const rapidjson::Value& obj) : UnlockContainerInstanceRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerInstanceRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.String("ContainerItemInstanceId");
                writer.String(ContainerItemInstanceId.c_str());
                if (KeyItemInstanceId.length() > 0) {
                    writer.String("KeyItemInstanceId");
                    writer.String(KeyItemInstanceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ContainerItemInstanceId_member = obj.FindMember("ContainerItemInstanceId");
                if (ContainerItemInstanceId_member != obj.MemberEnd() && !ContainerItemInstanceId_member->value.IsNull()) ContainerItemInstanceId = ContainerItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator KeyItemInstanceId_member = obj.FindMember("KeyItemInstanceId");
                if (KeyItemInstanceId_member != obj.MemberEnd() && !KeyItemInstanceId_member->value.IsNull()) KeyItemInstanceId = KeyItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct UnlockContainerItemRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CharacterId;
            AZStd::string ContainerItemId;

            UnlockContainerItemRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemId()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemId(src.ContainerItemId)
            {}

            UnlockContainerItemRequest(const rapidjson::Value& obj) : UnlockContainerItemRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.String("ContainerItemId");
                writer.String(ContainerItemId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ContainerItemId_member = obj.FindMember("ContainerItemId");
                if (ContainerItemId_member != obj.MemberEnd() && !ContainerItemId_member->value.IsNull()) ContainerItemId = ContainerItemId_member->value.GetString();

                return true;
            }
        };

        struct UnlockContainerItemResult : public PlayFabBaseModel
        {
            AZStd::vector<ItemInstance> GrantedItems; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string UnlockedItemInstanceId;
            AZStd::string UnlockedWithItemInstanceId;
            std::map<AZStd::string, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabBaseModel(),
                GrantedItems(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            UnlockContainerItemResult(const rapidjson::Value& obj) : UnlockContainerItemResult()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!GrantedItems.empty()) {
                    writer.String("GrantedItems");
                    writer.StartArray();
                    for (auto iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (UnlockedItemInstanceId.length() > 0) {
                    writer.String("UnlockedItemInstanceId");
                    writer.String(UnlockedItemInstanceId.c_str());
                }
                if (UnlockedWithItemInstanceId.length() > 0) {
                    writer.String("UnlockedWithItemInstanceId");
                    writer.String(UnlockedWithItemInstanceId.c_str());
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
                if (GrantedItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GrantedItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GrantedItems.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator UnlockedItemInstanceId_member = obj.FindMember("UnlockedItemInstanceId");
                if (UnlockedItemInstanceId_member != obj.MemberEnd() && !UnlockedItemInstanceId_member->value.IsNull()) UnlockedItemInstanceId = UnlockedItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator UnlockedWithItemInstanceId_member = obj.FindMember("UnlockedWithItemInstanceId");
                if (UnlockedWithItemInstanceId_member != obj.MemberEnd() && !UnlockedWithItemInstanceId_member->value.IsNull()) UnlockedWithItemInstanceId = UnlockedWithItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct UpdateAvatarUrlRequest : public PlayFabBaseModel
        {
            AZStd::string ImageUrl;

            UpdateAvatarUrlRequest() :
                PlayFabBaseModel(),
                ImageUrl()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabBaseModel(),
                ImageUrl(src.ImageUrl)
            {}

            UpdateAvatarUrlRequest(const rapidjson::Value& obj) : UpdateAvatarUrlRequest()
            {
                readFromValue(obj);
            }

            ~UpdateAvatarUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ImageUrl");
                writer.String(ImageUrl.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ImageUrl_member = obj.FindMember("ImageUrl");
                if (ImageUrl_member != obj.MemberEnd() && !ImageUrl_member->value.IsNull()) ImageUrl = ImageUrl_member->value.GetString();

                return true;
            }
        };

        struct UpdateCharacterDataRequest : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            std::map<AZStd::string, AZStd::string> Data;
            AZStd::vector<AZStd::string> KeysToRemove; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<UserDataPermission> Permission;

            UpdateCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateCharacterDataRequest(const rapidjson::Value& obj) : UpdateCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (auto iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
                if (KeysToRemove_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KeysToRemove_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KeysToRemove.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateCharacterDataResult : public PlayFabBaseModel
        {
            Uint32 DataVersion;

            UpdateCharacterDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateCharacterDataResult(const rapidjson::Value& obj) : UpdateCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct UpdateCharacterStatisticsRequest : public PlayFabBaseModel
        {
            AZStd::string CharacterId;
            std::map<AZStd::string, Int32> CharacterStatistics;

            UpdateCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterStatistics()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics)
            {}

            UpdateCharacterStatisticsRequest(const rapidjson::Value& obj) : UpdateCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (!CharacterStatistics.empty()) {
                    writer.String("CharacterStatistics");
                    writer.StartObject();
                    for (auto iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
                if (CharacterStatistics_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
                        CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
                    }
                }

                return true;
            }
        };

        struct UpdateCharacterStatisticsResult : public PlayFabBaseModel
        {

            UpdateCharacterStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const UpdateCharacterStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const rapidjson::Value& obj) : UpdateCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdatePlayerStatisticsRequest : public PlayFabBaseModel
        {
            AZStd::vector<StatisticUpdate> Statistics; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            UpdatePlayerStatisticsRequest() :
                PlayFabBaseModel(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            UpdatePlayerStatisticsRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Statistics");
                writer.StartArray();
                for (auto iter = Statistics.begin(); iter != Statistics.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
                if (Statistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statistics.push_back(StatisticUpdate(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UpdatePlayerStatisticsResult : public PlayFabBaseModel
        {

            UpdatePlayerStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const UpdatePlayerStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const rapidjson::Value& obj) : UpdatePlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdateSharedGroupDataRequest : public PlayFabBaseModel
        {
            std::map<AZStd::string, AZStd::string> Data;
            AZStd::vector<AZStd::string> KeysToRemove; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<UserDataPermission> Permission;
            AZStd::string SharedGroupId;

            UpdateSharedGroupDataRequest() :
                PlayFabBaseModel(),
                Data(),
                KeysToRemove(),
                Permission(),
                SharedGroupId()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                SharedGroupId(src.SharedGroupId)
            {}

            UpdateSharedGroupDataRequest(const rapidjson::Value& obj) : UpdateSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (auto iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
                if (KeysToRemove_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KeysToRemove_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KeysToRemove.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct UpdateSharedGroupDataResult : public PlayFabBaseModel
        {

            UpdateSharedGroupDataResult() :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const UpdateSharedGroupDataResult& src) :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const rapidjson::Value& obj) : UpdateSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdateUserDataRequest : public PlayFabBaseModel
        {
            std::map<AZStd::string, AZStd::string> Data;
            AZStd::vector<AZStd::string> KeysToRemove; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateUserDataRequest(const rapidjson::Value& obj) : UpdateUserDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (auto iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
                if (KeysToRemove_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KeysToRemove_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KeysToRemove.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateUserDataResult : public PlayFabBaseModel
        {
            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateUserDataResult(const rapidjson::Value& obj) : UpdateUserDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabBaseModel
        {
            AZStd::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameRequest(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("DisplayName");
                writer.String(DisplayName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameResult : public PlayFabBaseModel
        {
            AZStd::string DisplayName;

            UpdateUserTitleDisplayNameResult() :
                PlayFabBaseModel(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameResult(const UpdateUserTitleDisplayNameResult& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameResult(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

                return true;
            }
        };

        struct ValidateAmazonReceiptRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CurrencyCode;
            Int32 PurchasePrice;
            AZStd::string ReceiptId;
            AZStd::string UserId;

            ValidateAmazonReceiptRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(0),
                ReceiptId(),
                UserId()
            {}

            ValidateAmazonReceiptRequest(const ValidateAmazonReceiptRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptId(src.ReceiptId),
                UserId(src.UserId)
            {}

            ValidateAmazonReceiptRequest(const rapidjson::Value& obj) : ValidateAmazonReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateAmazonReceiptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("CurrencyCode");
                writer.String(CurrencyCode.c_str());
                writer.String("PurchasePrice");
                writer.Int(PurchasePrice);
                writer.String("ReceiptId");
                writer.String(ReceiptId.c_str());
                writer.String("UserId");
                writer.String(UserId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetInt();
                const Value::ConstMemberIterator ReceiptId_member = obj.FindMember("ReceiptId");
                if (ReceiptId_member != obj.MemberEnd() && !ReceiptId_member->value.IsNull()) ReceiptId = ReceiptId_member->value.GetString();
                const Value::ConstMemberIterator UserId_member = obj.FindMember("UserId");
                if (UserId_member != obj.MemberEnd() && !UserId_member->value.IsNull()) UserId = UserId_member->value.GetString();

                return true;
            }
        };

        struct ValidateAmazonReceiptResult : public PlayFabBaseModel
        {

            ValidateAmazonReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateAmazonReceiptResult(const ValidateAmazonReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateAmazonReceiptResult(const rapidjson::Value& obj) : ValidateAmazonReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateAmazonReceiptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ValidateGooglePlayPurchaseRequest : public PlayFabBaseModel
        {
            AZStd::string CurrencyCode;
            OptionalUint32 PurchasePrice;
            AZStd::string ReceiptJson;
            AZStd::string Signature;

            ValidateGooglePlayPurchaseRequest() :
                PlayFabBaseModel(),
                CurrencyCode(),
                PurchasePrice(),
                ReceiptJson(),
                Signature()
            {}

            ValidateGooglePlayPurchaseRequest(const ValidateGooglePlayPurchaseRequest& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptJson(src.ReceiptJson),
                Signature(src.Signature)
            {}

            ValidateGooglePlayPurchaseRequest(const rapidjson::Value& obj) : ValidateGooglePlayPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ValidateGooglePlayPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CurrencyCode.length() > 0) {
                    writer.String("CurrencyCode");
                    writer.String(CurrencyCode.c_str());
                }
                if (PurchasePrice.notNull()) {
                    writer.String("PurchasePrice");
                    writer.Uint(PurchasePrice);
                }
                writer.String("ReceiptJson");
                writer.String(ReceiptJson.c_str());
                writer.String("Signature");
                writer.String(Signature.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();
                const Value::ConstMemberIterator ReceiptJson_member = obj.FindMember("ReceiptJson");
                if (ReceiptJson_member != obj.MemberEnd() && !ReceiptJson_member->value.IsNull()) ReceiptJson = ReceiptJson_member->value.GetString();
                const Value::ConstMemberIterator Signature_member = obj.FindMember("Signature");
                if (Signature_member != obj.MemberEnd() && !Signature_member->value.IsNull()) Signature = Signature_member->value.GetString();

                return true;
            }
        };

        struct ValidateGooglePlayPurchaseResult : public PlayFabBaseModel
        {

            ValidateGooglePlayPurchaseResult() :
                PlayFabBaseModel()
            {}

            ValidateGooglePlayPurchaseResult(const ValidateGooglePlayPurchaseResult& src) :
                PlayFabBaseModel()
            {}

            ValidateGooglePlayPurchaseResult(const rapidjson::Value& obj) : ValidateGooglePlayPurchaseResult()
            {
                readFromValue(obj);
            }

            ~ValidateGooglePlayPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ValidateIOSReceiptRequest : public PlayFabBaseModel
        {
            AZStd::string CurrencyCode;
            Int32 PurchasePrice;
            AZStd::string ReceiptData;

            ValidateIOSReceiptRequest() :
                PlayFabBaseModel(),
                CurrencyCode(),
                PurchasePrice(0),
                ReceiptData()
            {}

            ValidateIOSReceiptRequest(const ValidateIOSReceiptRequest& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptData(src.ReceiptData)
            {}

            ValidateIOSReceiptRequest(const rapidjson::Value& obj) : ValidateIOSReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateIOSReceiptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("CurrencyCode");
                writer.String(CurrencyCode.c_str());
                writer.String("PurchasePrice");
                writer.Int(PurchasePrice);
                writer.String("ReceiptData");
                writer.String(ReceiptData.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetInt();
                const Value::ConstMemberIterator ReceiptData_member = obj.FindMember("ReceiptData");
                if (ReceiptData_member != obj.MemberEnd() && !ReceiptData_member->value.IsNull()) ReceiptData = ReceiptData_member->value.GetString();

                return true;
            }
        };

        struct ValidateIOSReceiptResult : public PlayFabBaseModel
        {

            ValidateIOSReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateIOSReceiptResult(const ValidateIOSReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateIOSReceiptResult(const rapidjson::Value& obj) : ValidateIOSReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateIOSReceiptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ValidateWindowsReceiptRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string CurrencyCode;
            Uint32 PurchasePrice;
            AZStd::string Receipt;

            ValidateWindowsReceiptRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(0),
                Receipt()
            {}

            ValidateWindowsReceiptRequest(const ValidateWindowsReceiptRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                Receipt(src.Receipt)
            {}

            ValidateWindowsReceiptRequest(const rapidjson::Value& obj) : ValidateWindowsReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateWindowsReceiptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("CurrencyCode");
                writer.String(CurrencyCode.c_str());
                writer.String("PurchasePrice");
                writer.Uint(PurchasePrice);
                writer.String("Receipt");
                writer.String(Receipt.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();
                const Value::ConstMemberIterator Receipt_member = obj.FindMember("Receipt");
                if (Receipt_member != obj.MemberEnd() && !Receipt_member->value.IsNull()) Receipt = Receipt_member->value.GetString();

                return true;
            }
        };

        struct ValidateWindowsReceiptResult : public PlayFabBaseModel
        {

            ValidateWindowsReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateWindowsReceiptResult(const ValidateWindowsReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateWindowsReceiptResult(const rapidjson::Value& obj) : ValidateWindowsReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateWindowsReceiptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct WriteClientCharacterEventRequest : public PlayFabBaseModel
        {
            std::map<AZStd::string, MultitypeVar> Body;
            AZStd::string CharacterId;
            AZStd::string EventName;
            OptionalTime Timestamp;

            WriteClientCharacterEventRequest() :
                PlayFabBaseModel(),
                Body(),
                CharacterId(),
                EventName(),
                Timestamp()
            {}

            WriteClientCharacterEventRequest(const WriteClientCharacterEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                CharacterId(src.CharacterId),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            WriteClientCharacterEventRequest(const rapidjson::Value& obj) : WriteClientCharacterEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteClientCharacterEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Body.empty()) {
                    writer.String("Body");
                    writer.StartObject();
                    for (auto iter = Body.begin(); iter != Body.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                writer.String("EventName");
                writer.String(EventName.c_str());
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
                        Body[iter->name.GetString()] = MultitypeVar(iter->value);
                    }
                }
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);

                return true;
            }
        };

        struct WriteClientPlayerEventRequest : public PlayFabBaseModel
        {
            std::map<AZStd::string, MultitypeVar> Body;
            AZStd::string EventName;
            OptionalTime Timestamp;

            WriteClientPlayerEventRequest() :
                PlayFabBaseModel(),
                Body(),
                EventName(),
                Timestamp()
            {}

            WriteClientPlayerEventRequest(const WriteClientPlayerEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            WriteClientPlayerEventRequest(const rapidjson::Value& obj) : WriteClientPlayerEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteClientPlayerEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Body.empty()) {
                    writer.String("Body");
                    writer.StartObject();
                    for (auto iter = Body.begin(); iter != Body.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("EventName");
                writer.String(EventName.c_str());
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
                        Body[iter->name.GetString()] = MultitypeVar(iter->value);
                    }
                }
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);

                return true;
            }
        };

        struct WriteEventResponse : public PlayFabBaseModel
        {
            AZStd::string EventId;

            WriteEventResponse() :
                PlayFabBaseModel(),
                EventId()
            {}

            WriteEventResponse(const WriteEventResponse& src) :
                PlayFabBaseModel(),
                EventId(src.EventId)
            {}

            WriteEventResponse(const rapidjson::Value& obj) : WriteEventResponse()
            {
                readFromValue(obj);
            }

            ~WriteEventResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (EventId.length() > 0) {
                    writer.String("EventId");
                    writer.String(EventId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EventId_member = obj.FindMember("EventId");
                if (EventId_member != obj.MemberEnd() && !EventId_member->value.IsNull()) EventId = EventId_member->value.GetString();

                return true;
            }
        };

        struct WriteTitleEventRequest : public PlayFabBaseModel
        {
            std::map<AZStd::string, MultitypeVar> Body;
            AZStd::string EventName;
            OptionalTime Timestamp;

            WriteTitleEventRequest() :
                PlayFabBaseModel(),
                Body(),
                EventName(),
                Timestamp()
            {}

            WriteTitleEventRequest(const WriteTitleEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            WriteTitleEventRequest(const rapidjson::Value& obj) : WriteTitleEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteTitleEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Body.empty()) {
                    writer.String("Body");
                    writer.StartObject();
                    for (auto iter = Body.begin(); iter != Body.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("EventName");
                writer.String(EventName.c_str());
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
                        Body[iter->name.GetString()] = MultitypeVar(iter->value);
                    }
                }
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);

                return true;
            }
        };


    }
}
