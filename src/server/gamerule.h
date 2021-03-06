#ifndef GAMERULE_H
#define GAMERULE_H

#include "skill.h"

class GameRule : public TriggerSkill{
    Q_OBJECT

public:
    GameRule();
    void setGameProcess(Room *room) const;

    virtual bool triggerable(const ServerPlayer *target) const;
    virtual int getPriority() const;
    virtual bool trigger(TriggerEvent event, Room* room, ServerPlayer *player, QVariant &data) const;

private:
    void beforeNext(ServerPlayer *player) const;
    void onPhaseChange(ServerPlayer *player) const;
    void changeGeneral1v1(ServerPlayer *player) const;
    QString getWinner(ServerPlayer *victim) const;
    mutable jmp_buf danshou_env;
};

class HulaoPassMode: public GameRule{
    Q_OBJECT

public:
    HulaoPassMode();

    virtual bool trigger(TriggerEvent event, Room* room, ServerPlayer *player, QVariant &data) const;

private:
    mutable jmp_buf env;
};

class BasaraMode: public GameRule{
    Q_OBJECT

public:
    BasaraMode();

    virtual bool trigger(TriggerEvent event, Room* room, ServerPlayer *player, QVariant &data) const;
    virtual int getPriority() const;
    void playerShowed(ServerPlayer *player) const;
    void generalShowed(ServerPlayer *player,QString general_name) const;
    static QString getMappedRole(const QString& role);

private:
    QMap<QString, QString> skill_mark;
};

class ChangbanSlopeMode: public GameRule{
    Q_OBJECT

public:
    ChangbanSlopeMode();

    virtual bool trigger(TriggerEvent event, Room* room, ServerPlayer *player, QVariant &data) const;

private:
    void changeGeneral(ServerPlayer *player) const;
    mutable jmp_buf env;
};

class ReincarnationRule: public GameRule{
    Q_OBJECT

public:
    ReincarnationRule();

    virtual bool trigger(TriggerEvent event, Room* room, ServerPlayer *player, QVariant &data) const;
    virtual int getPriority() const;
};

#endif // GAMERULE_H
