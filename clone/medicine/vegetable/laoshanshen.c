// laoshanshen.c ��ɽ��

inherit ITEM;
#include <ansi.h>
void setup()
{
}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY "��ɽ��" NOR, ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("vegetable", 4);
		set("nostrum", 64);
		set("long", "����һ��մ��ɽ��ĳ�����ɽ�Ρ�\n");
		set("value", 10000);
	}
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy())
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	me->receive_curing("qi", 200);
	message_vision("$N����һ����ɽ�Σ��پ�����һ����������ð��������\n", me);
	destruct(this_object());
	return 1;
}