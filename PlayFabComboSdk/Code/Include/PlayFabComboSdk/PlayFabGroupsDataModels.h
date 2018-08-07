#pragma once

#include <PlayFabComboSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>

using namespace rapidjson;

namespace PlayFabComboSdk
{
    namespace GroupsModels
    {
        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup,
            EntityTypesservice
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
            case EntityTypesservice: writer.String("service"); break;

            }
        }

        inline EntityTypes readEntityTypesFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EntityTypes>(obj.GetInt());

            static std::map<const char *, EntityTypes, PlayFabComboSdk::StringCompare> _EntityTypesMap;
            if (_EntityTypesMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EntityTypesMap["title"] = EntityTypestitle;
                _EntityTypesMap["master_player_account"] = EntityTypesmaster_player_account;
                _EntityTypesMap["title_player_account"] = EntityTypestitle_player_account;
                _EntityTypesMap["character"] = EntityTypescharacter;
                _EntityTypesMap["group"] = EntityTypesgroup;
                _EntityTypesMap["service"] = EntityTypesservice;

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

        struct AcceptGroupApplicationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            AcceptGroupApplicationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            AcceptGroupApplicationRequest(const AcceptGroupApplicationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            AcceptGroupApplicationRequest(const rapidjson::Value& obj) : AcceptGroupApplicationRequest()
            {
                readFromValue(obj);
            }

            ~AcceptGroupApplicationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct AcceptGroupInvitationRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            EntityKey Group;

            AcceptGroupInvitationRequest() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Group()
            {}

            AcceptGroupInvitationRequest(const AcceptGroupInvitationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Group(src.Group)
            {}

            AcceptGroupInvitationRequest(const rapidjson::Value& obj) : AcceptGroupInvitationRequest()
            {
                readFromValue(obj);
            }

            ~AcceptGroupInvitationRequest()
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
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct AddMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::vector<EntityKey> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string RoleId;

            AddMembersRequest() :
                PlayFabBaseModel(),
                Group(),
                Members(),
                RoleId()
            {}

            AddMembersRequest(const AddMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            AddMembersRequest(const rapidjson::Value& obj) : AddMembersRequest()
            {
                readFromValue(obj);
            }

            ~AddMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("Members");
                writer.StartArray();
                for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityKey(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct ApplyToGroupRequest : public PlayFabBaseModel
        {
            OptionalBool AutoAcceptOutstandingInvite;
            EntityKey* Entity;
            EntityKey Group;

            ApplyToGroupRequest() :
                PlayFabBaseModel(),
                AutoAcceptOutstandingInvite(),
                Entity(nullptr),
                Group()
            {}

            ApplyToGroupRequest(const ApplyToGroupRequest& src) :
                PlayFabBaseModel(),
                AutoAcceptOutstandingInvite(src.AutoAcceptOutstandingInvite),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Group(src.Group)
            {}

            ApplyToGroupRequest(const rapidjson::Value& obj) : ApplyToGroupRequest()
            {
                readFromValue(obj);
            }

            ~ApplyToGroupRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AutoAcceptOutstandingInvite.notNull()) {
                    writer.String("AutoAcceptOutstandingInvite");
                    writer.Bool(AutoAcceptOutstandingInvite);
                }
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AutoAcceptOutstandingInvite_member = obj.FindMember("AutoAcceptOutstandingInvite");
                if (AutoAcceptOutstandingInvite_member != obj.MemberEnd() && !AutoAcceptOutstandingInvite_member->value.IsNull()) AutoAcceptOutstandingInvite = AutoAcceptOutstandingInvite_member->value.GetBool();
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct EntityWithLineage : public PlayFabBaseModel
        {
            EntityKey* Key;
            std::map<AZStd::string, EntityKey> Lineage;

            EntityWithLineage() :
                PlayFabBaseModel(),
                Key(nullptr),
                Lineage()
            {}

            EntityWithLineage(const EntityWithLineage& src) :
                PlayFabBaseModel(),
                Key(src.Key ? new EntityKey(*src.Key) : nullptr),
                Lineage(src.Lineage)
            {}

            EntityWithLineage(const rapidjson::Value& obj) : EntityWithLineage()
            {
                readFromValue(obj);
            }

            ~EntityWithLineage()
            {
                if (Key != nullptr) delete Key;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Key != nullptr) {
                    writer.String("Key");
                    Key->writeJSON(writer);
                }
                if (!Lineage.empty()) {
                    writer.String("Lineage");
                    writer.StartObject();
                    for (auto iter = Lineage.begin(); iter != Lineage.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = new EntityKey(Key_member->value);
                const Value::ConstMemberIterator Lineage_member = obj.FindMember("Lineage");
                if (Lineage_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Lineage_member->value.MemberBegin(); iter != Lineage_member->value.MemberEnd(); ++iter) {
                        Lineage[iter->name.GetString()] = EntityKey(iter->value);
                    }
                }

                return true;
            }
        };

        struct ApplyToGroupResponse : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            time_t Expires;
            EntityKey* Group;

            ApplyToGroupResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Expires(0),
                Group(nullptr)
            {}

            ApplyToGroupResponse(const ApplyToGroupResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : nullptr),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr)
            {}

            ApplyToGroupResponse(const rapidjson::Value& obj) : ApplyToGroupResponse()
            {
                readFromValue(obj);
            }

            ~ApplyToGroupResponse()
            {
                if (Entity != nullptr) delete Entity;
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);

                return true;
            }
        };

        struct BlockEntityRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            BlockEntityRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            BlockEntityRequest(const BlockEntityRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            BlockEntityRequest(const rapidjson::Value& obj) : BlockEntityRequest()
            {
                readFromValue(obj);
            }

            ~BlockEntityRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ChangeMemberRoleRequest : public PlayFabBaseModel
        {
            AZStd::string DestinationRoleId;
            EntityKey Group;
            AZStd::vector<EntityKey> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string OriginRoleId;

            ChangeMemberRoleRequest() :
                PlayFabBaseModel(),
                DestinationRoleId(),
                Group(),
                Members(),
                OriginRoleId()
            {}

            ChangeMemberRoleRequest(const ChangeMemberRoleRequest& src) :
                PlayFabBaseModel(),
                DestinationRoleId(src.DestinationRoleId),
                Group(src.Group),
                Members(src.Members),
                OriginRoleId(src.OriginRoleId)
            {}

            ChangeMemberRoleRequest(const rapidjson::Value& obj) : ChangeMemberRoleRequest()
            {
                readFromValue(obj);
            }

            ~ChangeMemberRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DestinationRoleId.length() > 0) {
                    writer.String("DestinationRoleId");
                    writer.String(DestinationRoleId.c_str());
                }
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("Members");
                writer.StartArray();
                for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.String("OriginRoleId");
                writer.String(OriginRoleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DestinationRoleId_member = obj.FindMember("DestinationRoleId");
                if (DestinationRoleId_member != obj.MemberEnd() && !DestinationRoleId_member->value.IsNull()) DestinationRoleId = DestinationRoleId_member->value.GetString();
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityKey(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator OriginRoleId_member = obj.FindMember("OriginRoleId");
                if (OriginRoleId_member != obj.MemberEnd() && !OriginRoleId_member->value.IsNull()) OriginRoleId = OriginRoleId_member->value.GetString();

                return true;
            }
        };

        struct CreateGroupRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            AZStd::string GroupName;

            CreateGroupRequest() :
                PlayFabBaseModel(),
                Entity(nullptr),
                GroupName()
            {}

            CreateGroupRequest(const CreateGroupRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                GroupName(src.GroupName)
            {}

            CreateGroupRequest(const rapidjson::Value& obj) : CreateGroupRequest()
            {
                readFromValue(obj);
            }

            ~CreateGroupRequest()
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
                writer.String("GroupName");
                writer.String(GroupName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();

                return true;
            }
        };

        struct CreateGroupResponse : public PlayFabBaseModel
        {
            AZStd::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            AZStd::string GroupName;
            AZStd::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<AZStd::string, AZStd::string> Roles;

            CreateGroupResponse() :
                PlayFabBaseModel(),
                AdminRoleId(),
                Created(0),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(0),
                Roles()
            {}

            CreateGroupResponse(const CreateGroupResponse& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            CreateGroupResponse(const rapidjson::Value& obj) : CreateGroupResponse()
            {
                readFromValue(obj);
            }

            ~CreateGroupResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AdminRoleId.length() > 0) {
                    writer.String("AdminRoleId");
                    writer.String(AdminRoleId.c_str());
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                if (MemberRoleId.length() > 0) {
                    writer.String("MemberRoleId");
                    writer.String(MemberRoleId.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!Roles.empty()) {
                    writer.String("Roles");
                    writer.StartObject();
                    for (auto iter = Roles.begin(); iter != Roles.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
                if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
                if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
                if (Roles_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Roles_member->value.MemberBegin(); iter != Roles_member->value.MemberEnd(); ++iter) {
                        Roles[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct CreateGroupRoleRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::string RoleId;
            AZStd::string RoleName;

            CreateGroupRoleRequest() :
                PlayFabBaseModel(),
                Group(),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleRequest(const CreateGroupRoleRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            CreateGroupRoleRequest(const rapidjson::Value& obj) : CreateGroupRoleRequest()
            {
                readFromValue(obj);
            }

            ~CreateGroupRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("RoleId");
                writer.String(RoleId.c_str());
                writer.String("RoleName");
                writer.String(RoleName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct CreateGroupRoleResponse : public PlayFabBaseModel
        {
            Int32 ProfileVersion;
            AZStd::string RoleId;
            AZStd::string RoleName;

            CreateGroupRoleResponse() :
                PlayFabBaseModel(),
                ProfileVersion(0),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleResponse(const CreateGroupRoleResponse& src) :
                PlayFabBaseModel(),
                ProfileVersion(src.ProfileVersion),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            CreateGroupRoleResponse(const rapidjson::Value& obj) : CreateGroupRoleResponse()
            {
                readFromValue(obj);
            }

            ~CreateGroupRoleResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                if (RoleName.length() > 0) {
                    writer.String("RoleName");
                    writer.String(RoleName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct DeleteGroupRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            DeleteGroupRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            DeleteGroupRequest(const DeleteGroupRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            DeleteGroupRequest(const rapidjson::Value& obj) : DeleteGroupRequest()
            {
                readFromValue(obj);
            }

            ~DeleteGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct DeleteRoleRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::string RoleId;

            DeleteRoleRequest() :
                PlayFabBaseModel(),
                Group(),
                RoleId()
            {}

            DeleteRoleRequest(const DeleteRoleRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            DeleteRoleRequest(const rapidjson::Value& obj) : DeleteRoleRequest()
            {
                readFromValue(obj);
            }

            ~DeleteRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

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

        struct EntityMemberRole : public PlayFabBaseModel
        {
            AZStd::vector<EntityWithLineage> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string RoleId;
            AZStd::string RoleName;

            EntityMemberRole() :
                PlayFabBaseModel(),
                Members(),
                RoleId(),
                RoleName()
            {}

            EntityMemberRole(const EntityMemberRole& src) :
                PlayFabBaseModel(),
                Members(src.Members),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            EntityMemberRole(const rapidjson::Value& obj) : EntityMemberRole()
            {
                readFromValue(obj);
            }

            ~EntityMemberRole()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Members.empty()) {
                    writer.String("Members");
                    writer.StartArray();
                    for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                if (RoleName.length() > 0) {
                    writer.String("RoleName");
                    writer.String(RoleName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityWithLineage(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct GetGroupRequest : public PlayFabBaseModel
        {
            EntityKey* Group;
            AZStd::string GroupName;

            GetGroupRequest() :
                PlayFabBaseModel(),
                Group(nullptr),
                GroupName()
            {}

            GetGroupRequest(const GetGroupRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                GroupName(src.GroupName)
            {}

            GetGroupRequest(const rapidjson::Value& obj) : GetGroupRequest()
            {
                readFromValue(obj);
            }

            ~GetGroupRequest()
            {
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();

                return true;
            }
        };

        struct GetGroupResponse : public PlayFabBaseModel
        {
            AZStd::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            AZStd::string GroupName;
            AZStd::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<AZStd::string, AZStd::string> Roles;

            GetGroupResponse() :
                PlayFabBaseModel(),
                AdminRoleId(),
                Created(0),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(0),
                Roles()
            {}

            GetGroupResponse(const GetGroupResponse& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            GetGroupResponse(const rapidjson::Value& obj) : GetGroupResponse()
            {
                readFromValue(obj);
            }

            ~GetGroupResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AdminRoleId.length() > 0) {
                    writer.String("AdminRoleId");
                    writer.String(AdminRoleId.c_str());
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                if (MemberRoleId.length() > 0) {
                    writer.String("MemberRoleId");
                    writer.String(MemberRoleId.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!Roles.empty()) {
                    writer.String("Roles");
                    writer.StartObject();
                    for (auto iter = Roles.begin(); iter != Roles.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
                if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
                if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
                if (Roles_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Roles_member->value.MemberBegin(); iter != Roles_member->value.MemberEnd(); ++iter) {
                        Roles[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct GroupApplication : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            time_t Expires;
            EntityKey* Group;

            GroupApplication() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Expires(0),
                Group(nullptr)
            {}

            GroupApplication(const GroupApplication& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : nullptr),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr)
            {}

            GroupApplication(const rapidjson::Value& obj) : GroupApplication()
            {
                readFromValue(obj);
            }

            ~GroupApplication()
            {
                if (Entity != nullptr) delete Entity;
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);

                return true;
            }
        };

        struct GroupBlock : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            EntityKey Group;

            GroupBlock() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Group()
            {}

            GroupBlock(const GroupBlock& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : nullptr),
                Group(src.Group)
            {}

            GroupBlock(const rapidjson::Value& obj) : GroupBlock()
            {
                readFromValue(obj);
            }

            ~GroupBlock()
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
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct GroupInvitation : public PlayFabBaseModel
        {
            time_t Expires;
            EntityKey* Group;
            EntityWithLineage* InvitedByEntity;
            EntityWithLineage* InvitedEntity;
            AZStd::string RoleId;

            GroupInvitation() :
                PlayFabBaseModel(),
                Expires(0),
                Group(nullptr),
                InvitedByEntity(nullptr),
                InvitedEntity(nullptr),
                RoleId()
            {}

            GroupInvitation(const GroupInvitation& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                InvitedByEntity(src.InvitedByEntity ? new EntityWithLineage(*src.InvitedByEntity) : nullptr),
                InvitedEntity(src.InvitedEntity ? new EntityWithLineage(*src.InvitedEntity) : nullptr),
                RoleId(src.RoleId)
            {}

            GroupInvitation(const rapidjson::Value& obj) : GroupInvitation()
            {
                readFromValue(obj);
            }

            ~GroupInvitation()
            {
                if (Group != nullptr) delete Group;
                if (InvitedByEntity != nullptr) delete InvitedByEntity;
                if (InvitedEntity != nullptr) delete InvitedEntity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (InvitedByEntity != nullptr) {
                    writer.String("InvitedByEntity");
                    InvitedByEntity->writeJSON(writer);
                }
                if (InvitedEntity != nullptr) {
                    writer.String("InvitedEntity");
                    InvitedEntity->writeJSON(writer);
                }
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator InvitedByEntity_member = obj.FindMember("InvitedByEntity");
                if (InvitedByEntity_member != obj.MemberEnd() && !InvitedByEntity_member->value.IsNull()) InvitedByEntity = new EntityWithLineage(InvitedByEntity_member->value);
                const Value::ConstMemberIterator InvitedEntity_member = obj.FindMember("InvitedEntity");
                if (InvitedEntity_member != obj.MemberEnd() && !InvitedEntity_member->value.IsNull()) InvitedEntity = new EntityWithLineage(InvitedEntity_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct GroupRole : public PlayFabBaseModel
        {
            AZStd::string RoleId;
            AZStd::string RoleName;

            GroupRole() :
                PlayFabBaseModel(),
                RoleId(),
                RoleName()
            {}

            GroupRole(const GroupRole& src) :
                PlayFabBaseModel(),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            GroupRole(const rapidjson::Value& obj) : GroupRole()
            {
                readFromValue(obj);
            }

            ~GroupRole()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                if (RoleName.length() > 0) {
                    writer.String("RoleName");
                    writer.String(RoleName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct GroupWithRoles : public PlayFabBaseModel
        {
            EntityKey* Group;
            AZStd::string GroupName;
            Int32 ProfileVersion;
            AZStd::vector<GroupRole> Roles; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GroupWithRoles() :
                PlayFabBaseModel(),
                Group(nullptr),
                GroupName(),
                ProfileVersion(0),
                Roles()
            {}

            GroupWithRoles(const GroupWithRoles& src) :
                PlayFabBaseModel(),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                GroupName(src.GroupName),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            GroupWithRoles(const rapidjson::Value& obj) : GroupWithRoles()
            {
                readFromValue(obj);
            }

            ~GroupWithRoles()
            {
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!Roles.empty()) {
                    writer.String("Roles");
                    writer.StartArray();
                    for (auto iter = Roles.begin(); iter != Roles.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
                if (Roles_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Roles_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Roles.push_back(GroupRole(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct InviteToGroupRequest : public PlayFabBaseModel
        {
            OptionalBool AutoAcceptOutstandingApplication;
            EntityKey Entity;
            EntityKey Group;
            AZStd::string RoleId;

            InviteToGroupRequest() :
                PlayFabBaseModel(),
                AutoAcceptOutstandingApplication(),
                Entity(),
                Group(),
                RoleId()
            {}

            InviteToGroupRequest(const InviteToGroupRequest& src) :
                PlayFabBaseModel(),
                AutoAcceptOutstandingApplication(src.AutoAcceptOutstandingApplication),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            InviteToGroupRequest(const rapidjson::Value& obj) : InviteToGroupRequest()
            {
                readFromValue(obj);
            }

            ~InviteToGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AutoAcceptOutstandingApplication.notNull()) {
                    writer.String("AutoAcceptOutstandingApplication");
                    writer.Bool(AutoAcceptOutstandingApplication);
                }
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AutoAcceptOutstandingApplication_member = obj.FindMember("AutoAcceptOutstandingApplication");
                if (AutoAcceptOutstandingApplication_member != obj.MemberEnd() && !AutoAcceptOutstandingApplication_member->value.IsNull()) AutoAcceptOutstandingApplication = AutoAcceptOutstandingApplication_member->value.GetBool();
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct InviteToGroupResponse : public PlayFabBaseModel
        {
            time_t Expires;
            EntityKey* Group;
            EntityWithLineage* InvitedByEntity;
            EntityWithLineage* InvitedEntity;
            AZStd::string RoleId;

            InviteToGroupResponse() :
                PlayFabBaseModel(),
                Expires(0),
                Group(nullptr),
                InvitedByEntity(nullptr),
                InvitedEntity(nullptr),
                RoleId()
            {}

            InviteToGroupResponse(const InviteToGroupResponse& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                InvitedByEntity(src.InvitedByEntity ? new EntityWithLineage(*src.InvitedByEntity) : nullptr),
                InvitedEntity(src.InvitedEntity ? new EntityWithLineage(*src.InvitedEntity) : nullptr),
                RoleId(src.RoleId)
            {}

            InviteToGroupResponse(const rapidjson::Value& obj) : InviteToGroupResponse()
            {
                readFromValue(obj);
            }

            ~InviteToGroupResponse()
            {
                if (Group != nullptr) delete Group;
                if (InvitedByEntity != nullptr) delete InvitedByEntity;
                if (InvitedEntity != nullptr) delete InvitedEntity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (InvitedByEntity != nullptr) {
                    writer.String("InvitedByEntity");
                    InvitedByEntity->writeJSON(writer);
                }
                if (InvitedEntity != nullptr) {
                    writer.String("InvitedEntity");
                    InvitedEntity->writeJSON(writer);
                }
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator InvitedByEntity_member = obj.FindMember("InvitedByEntity");
                if (InvitedByEntity_member != obj.MemberEnd() && !InvitedByEntity_member->value.IsNull()) InvitedByEntity = new EntityWithLineage(InvitedByEntity_member->value);
                const Value::ConstMemberIterator InvitedEntity_member = obj.FindMember("InvitedEntity");
                if (InvitedEntity_member != obj.MemberEnd() && !InvitedEntity_member->value.IsNull()) InvitedEntity = new EntityWithLineage(InvitedEntity_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct IsMemberRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;
            AZStd::string RoleId;

            IsMemberRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group(),
                RoleId()
            {}

            IsMemberRequest(const IsMemberRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            IsMemberRequest(const rapidjson::Value& obj) : IsMemberRequest()
            {
                readFromValue(obj);
            }

            ~IsMemberRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct IsMemberResponse : public PlayFabBaseModel
        {
            bool IsMember;

            IsMemberResponse() :
                PlayFabBaseModel(),
                IsMember(false)
            {}

            IsMemberResponse(const IsMemberResponse& src) :
                PlayFabBaseModel(),
                IsMember(src.IsMember)
            {}

            IsMemberResponse(const rapidjson::Value& obj) : IsMemberResponse()
            {
                readFromValue(obj);
            }

            ~IsMemberResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("IsMember");
                writer.Bool(IsMember);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IsMember_member = obj.FindMember("IsMember");
                if (IsMember_member != obj.MemberEnd() && !IsMember_member->value.IsNull()) IsMember = IsMember_member->value.GetBool();

                return true;
            }
        };

        struct ListGroupApplicationsRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupApplicationsRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupApplicationsRequest(const ListGroupApplicationsRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupApplicationsRequest(const rapidjson::Value& obj) : ListGroupApplicationsRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupApplicationsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupApplicationsResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupApplication> Applications; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupApplicationsResponse() :
                PlayFabBaseModel(),
                Applications()
            {}

            ListGroupApplicationsResponse(const ListGroupApplicationsResponse& src) :
                PlayFabBaseModel(),
                Applications(src.Applications)
            {}

            ListGroupApplicationsResponse(const rapidjson::Value& obj) : ListGroupApplicationsResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupApplicationsResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Applications.empty()) {
                    writer.String("Applications");
                    writer.StartArray();
                    for (auto iter = Applications.begin(); iter != Applications.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Applications_member = obj.FindMember("Applications");
                if (Applications_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Applications_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Applications.push_back(GroupApplication(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListGroupBlocksRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupBlocksRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupBlocksRequest(const ListGroupBlocksRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupBlocksRequest(const rapidjson::Value& obj) : ListGroupBlocksRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupBlocksRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupBlocksResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupBlock> BlockedEntities; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupBlocksResponse() :
                PlayFabBaseModel(),
                BlockedEntities()
            {}

            ListGroupBlocksResponse(const ListGroupBlocksResponse& src) :
                PlayFabBaseModel(),
                BlockedEntities(src.BlockedEntities)
            {}

            ListGroupBlocksResponse(const rapidjson::Value& obj) : ListGroupBlocksResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupBlocksResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!BlockedEntities.empty()) {
                    writer.String("BlockedEntities");
                    writer.StartArray();
                    for (auto iter = BlockedEntities.begin(); iter != BlockedEntities.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BlockedEntities_member = obj.FindMember("BlockedEntities");
                if (BlockedEntities_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BlockedEntities_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BlockedEntities.push_back(GroupBlock(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListGroupInvitationsRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupInvitationsRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupInvitationsRequest(const ListGroupInvitationsRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupInvitationsRequest(const rapidjson::Value& obj) : ListGroupInvitationsRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupInvitationsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupInvitationsResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupInvitation> Invitations; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupInvitationsResponse() :
                PlayFabBaseModel(),
                Invitations()
            {}

            ListGroupInvitationsResponse(const ListGroupInvitationsResponse& src) :
                PlayFabBaseModel(),
                Invitations(src.Invitations)
            {}

            ListGroupInvitationsResponse(const rapidjson::Value& obj) : ListGroupInvitationsResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupInvitationsResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Invitations.empty()) {
                    writer.String("Invitations");
                    writer.StartArray();
                    for (auto iter = Invitations.begin(); iter != Invitations.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Invitations_member = obj.FindMember("Invitations");
                if (Invitations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Invitations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Invitations.push_back(GroupInvitation(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListGroupMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupMembersRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupMembersRequest(const ListGroupMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupMembersRequest(const rapidjson::Value& obj) : ListGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupMembersResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityMemberRole> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupMembersResponse() :
                PlayFabBaseModel(),
                Members()
            {}

            ListGroupMembersResponse(const ListGroupMembersResponse& src) :
                PlayFabBaseModel(),
                Members(src.Members)
            {}

            ListGroupMembersResponse(const rapidjson::Value& obj) : ListGroupMembersResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupMembersResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Members.empty()) {
                    writer.String("Members");
                    writer.StartArray();
                    for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityMemberRole(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListMembershipOpportunitiesRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            ListMembershipOpportunitiesRequest() :
                PlayFabBaseModel(),
                Entity(nullptr)
            {}

            ListMembershipOpportunitiesRequest(const ListMembershipOpportunitiesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr)
            {}

            ListMembershipOpportunitiesRequest(const rapidjson::Value& obj) : ListMembershipOpportunitiesRequest()
            {
                readFromValue(obj);
            }

            ~ListMembershipOpportunitiesRequest()
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
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

                return true;
            }
        };

        struct ListMembershipOpportunitiesResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupApplication> Applications; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<GroupInvitation> Invitations; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListMembershipOpportunitiesResponse() :
                PlayFabBaseModel(),
                Applications(),
                Invitations()
            {}

            ListMembershipOpportunitiesResponse(const ListMembershipOpportunitiesResponse& src) :
                PlayFabBaseModel(),
                Applications(src.Applications),
                Invitations(src.Invitations)
            {}

            ListMembershipOpportunitiesResponse(const rapidjson::Value& obj) : ListMembershipOpportunitiesResponse()
            {
                readFromValue(obj);
            }

            ~ListMembershipOpportunitiesResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Applications.empty()) {
                    writer.String("Applications");
                    writer.StartArray();
                    for (auto iter = Applications.begin(); iter != Applications.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Invitations.empty()) {
                    writer.String("Invitations");
                    writer.StartArray();
                    for (auto iter = Invitations.begin(); iter != Invitations.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Applications_member = obj.FindMember("Applications");
                if (Applications_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Applications_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Applications.push_back(GroupApplication(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Invitations_member = obj.FindMember("Invitations");
                if (Invitations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Invitations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Invitations.push_back(GroupInvitation(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListMembershipRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            ListMembershipRequest() :
                PlayFabBaseModel(),
                Entity(nullptr)
            {}

            ListMembershipRequest(const ListMembershipRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr)
            {}

            ListMembershipRequest(const rapidjson::Value& obj) : ListMembershipRequest()
            {
                readFromValue(obj);
            }

            ~ListMembershipRequest()
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
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

                return true;
            }
        };

        struct ListMembershipResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupWithRoles> Groups; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListMembershipResponse() :
                PlayFabBaseModel(),
                Groups()
            {}

            ListMembershipResponse(const ListMembershipResponse& src) :
                PlayFabBaseModel(),
                Groups(src.Groups)
            {}

            ListMembershipResponse(const rapidjson::Value& obj) : ListMembershipResponse()
            {
                readFromValue(obj);
            }

            ~ListMembershipResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Groups.empty()) {
                    writer.String("Groups");
                    writer.StartArray();
                    for (auto iter = Groups.begin(); iter != Groups.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Groups_member = obj.FindMember("Groups");
                if (Groups_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Groups_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Groups.push_back(GroupWithRoles(memberList[i]));
                    }
                }

                return true;
            }
        };

        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        inline void writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case OperationTypesCreated: writer.String("Created"); break;
            case OperationTypesUpdated: writer.String("Updated"); break;
            case OperationTypesDeleted: writer.String("Deleted"); break;
            case OperationTypesNone: writer.String("None"); break;

            }
        }

        inline OperationTypes readOperationTypesFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<OperationTypes>(obj.GetInt());

            static std::map<const char *, OperationTypes, PlayFabComboSdk::StringCompare> _OperationTypesMap;
            if (_OperationTypesMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _OperationTypesMap["Created"] = OperationTypesCreated;
                _OperationTypesMap["Updated"] = OperationTypesUpdated;
                _OperationTypesMap["Deleted"] = OperationTypesDeleted;
                _OperationTypesMap["None"] = OperationTypesNone;

            }

            auto output = _OperationTypesMap.find(obj.GetString());
            if (output != _OperationTypesMap.end())
                return output->second;

            return OperationTypesCreated; // Basically critical fail
        }

        struct RemoveGroupApplicationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupApplicationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            RemoveGroupApplicationRequest(const RemoveGroupApplicationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            RemoveGroupApplicationRequest(const rapidjson::Value& obj) : RemoveGroupApplicationRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGroupApplicationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct RemoveGroupInvitationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupInvitationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            RemoveGroupInvitationRequest(const RemoveGroupInvitationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            RemoveGroupInvitationRequest(const rapidjson::Value& obj) : RemoveGroupInvitationRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGroupInvitationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct RemoveMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::vector<EntityKey> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string RoleId;

            RemoveMembersRequest() :
                PlayFabBaseModel(),
                Group(),
                Members(),
                RoleId()
            {}

            RemoveMembersRequest(const RemoveMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            RemoveMembersRequest(const rapidjson::Value& obj) : RemoveMembersRequest()
            {
                readFromValue(obj);
            }

            ~RemoveMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("Members");
                writer.StartArray();
                for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityKey(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct UnblockEntityRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            UnblockEntityRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            UnblockEntityRequest(const UnblockEntityRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            UnblockEntityRequest(const rapidjson::Value& obj) : UnblockEntityRequest()
            {
                readFromValue(obj);
            }

            ~UnblockEntityRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct UpdateGroupRequest : public PlayFabBaseModel
        {
            AZStd::string AdminRoleId;
            OptionalInt32 ExpectedProfileVersion;
            EntityKey Group;
            AZStd::string GroupName;
            AZStd::string MemberRoleId;

            UpdateGroupRequest() :
                PlayFabBaseModel(),
                AdminRoleId(),
                ExpectedProfileVersion(),
                Group(),
                GroupName(),
                MemberRoleId()
            {}

            UpdateGroupRequest(const UpdateGroupRequest& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId)
            {}

            UpdateGroupRequest(const rapidjson::Value& obj) : UpdateGroupRequest()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AdminRoleId.length() > 0) {
                    writer.String("AdminRoleId");
                    writer.String(AdminRoleId.c_str());
                }
                if (ExpectedProfileVersion.notNull()) {
                    writer.String("ExpectedProfileVersion");
                    writer.Int(ExpectedProfileVersion);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                if (MemberRoleId.length() > 0) {
                    writer.String("MemberRoleId");
                    writer.String(MemberRoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
                if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
                const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
                if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
                if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();

                return true;
            }
        };

        struct UpdateGroupResponse : public PlayFabBaseModel
        {
            AZStd::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupResponse() :
                PlayFabBaseModel(),
                OperationReason(),
                ProfileVersion(0),
                SetResult()
            {}

            UpdateGroupResponse(const UpdateGroupResponse& src) :
                PlayFabBaseModel(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            UpdateGroupResponse(const rapidjson::Value& obj) : UpdateGroupResponse()
            {
                readFromValue(obj);
            }

            ~UpdateGroupResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (OperationReason.length() > 0) {
                    writer.String("OperationReason");
                    writer.String(OperationReason.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (SetResult.notNull()) {
                    writer.String("SetResult");
                    writeOperationTypesEnumJSON(SetResult, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
                if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
                if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

                return true;
            }
        };

        struct UpdateGroupRoleRequest : public PlayFabBaseModel
        {
            OptionalInt32 ExpectedProfileVersion;
            EntityKey Group;
            AZStd::string RoleId;
            AZStd::string RoleName;

            UpdateGroupRoleRequest() :
                PlayFabBaseModel(),
                ExpectedProfileVersion(),
                Group(),
                RoleId(),
                RoleName()
            {}

            UpdateGroupRoleRequest(const UpdateGroupRoleRequest& src) :
                PlayFabBaseModel(),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            UpdateGroupRoleRequest(const rapidjson::Value& obj) : UpdateGroupRoleRequest()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ExpectedProfileVersion.notNull()) {
                    writer.String("ExpectedProfileVersion");
                    writer.Int(ExpectedProfileVersion);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.String("RoleName");
                writer.String(RoleName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
                if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct UpdateGroupRoleResponse : public PlayFabBaseModel
        {
            AZStd::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupRoleResponse() :
                PlayFabBaseModel(),
                OperationReason(),
                ProfileVersion(0),
                SetResult()
            {}

            UpdateGroupRoleResponse(const UpdateGroupRoleResponse& src) :
                PlayFabBaseModel(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            UpdateGroupRoleResponse(const rapidjson::Value& obj) : UpdateGroupRoleResponse()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRoleResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (OperationReason.length() > 0) {
                    writer.String("OperationReason");
                    writer.String(OperationReason.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (SetResult.notNull()) {
                    writer.String("SetResult");
                    writeOperationTypesEnumJSON(SetResult, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
                if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
                if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

                return true;
            }
        };


    }
}
