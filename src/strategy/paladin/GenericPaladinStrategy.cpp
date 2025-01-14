/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "GenericPaladinStrategy.h"
#include "GenericPaladinStrategyActionNodeFactory.h"
#include "Playerbots.h"

GenericPaladinStrategy::GenericPaladinStrategy(PlayerbotAI* botAI) : CombatStrategy(botAI)
{
    actionNodeFactories.Add(new GenericPaladinStrategyActionNodeFactory());
}

void GenericPaladinStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    CombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("enemy out of melee", NextAction::array(0, new NextAction("reach melee", ACTION_NORMAL), nullptr)));
    triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("divine shield", ACTION_CRITICAL_HEAL + 2), new NextAction("holy light", ACTION_CRITICAL_HEAL + 2), nullptr)));
    triggers.push_back(new TriggerNode("hammer of justice interrupt", NextAction::array(0, new NextAction("hammer of justice", ACTION_INTERRUPT), nullptr)));
    triggers.push_back(new TriggerNode("hammer of justice on enemy healer", NextAction::array(0, new NextAction("hammer of justice on enemy healer", ACTION_INTERRUPT), nullptr)));
    triggers.push_back(new TriggerNode("hammer of justice on snare target", NextAction::array(0, new NextAction("hammer of justice on snare target", ACTION_INTERRUPT), nullptr)));
    triggers.push_back(new TriggerNode("critical health", NextAction::array(0, new NextAction("lay on hands", ACTION_EMERGENCY), nullptr)));
    triggers.push_back(new TriggerNode("party member critical health", NextAction::array(0, new NextAction("lay on hands on party", ACTION_EMERGENCY + 1), nullptr)));
    triggers.push_back(new TriggerNode("protect party member", NextAction::array(0, new NextAction("blessing of protection on party", ACTION_EMERGENCY + 2), nullptr)));
}

void PaladinCureStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode("cleanse cure disease", NextAction::array(0, new NextAction("cleanse disease", ACTION_DISPEL + 2), nullptr)));
    triggers.push_back(new TriggerNode("cleanse party member cure disease", NextAction::array(0, new NextAction("cleanse disease on party", ACTION_DISPEL + 1), nullptr)));
    triggers.push_back(new TriggerNode("cleanse cure poison", NextAction::array(0, new NextAction("cleanse poison", ACTION_DISPEL + 2), nullptr)));
    triggers.push_back(new TriggerNode("cleanse party member cure poison", NextAction::array(0, new NextAction("cleanse poison on party", ACTION_DISPEL + 1), nullptr)));
    triggers.push_back(new TriggerNode("cleanse cure magic", NextAction::array(0, new NextAction("cleanse magic", ACTION_DISPEL + 2), nullptr)));
    triggers.push_back(new TriggerNode("cleanse party member cure magic", NextAction::array(0, new NextAction("cleanse magic on party", ACTION_DISPEL + 1), nullptr)));
}

void PaladinBoostStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode("avenging wrath", NextAction::array(0, new NextAction("avenging wrath", ACTION_HIGH + 2), nullptr)));
    triggers.push_back(new TriggerNode("divine favor", NextAction::array(0, new NextAction("divine favor", ACTION_HIGH + 1), nullptr)));
}

void PaladinCcStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode("turn undead", NextAction::array(0, new NextAction("turn undead", ACTION_HIGH + 1), nullptr)));
}
