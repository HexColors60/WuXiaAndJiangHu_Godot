// tangshi_book.c

inherit ITEM;

void create()
{
	set_name("��ʫ����", ({"tangshi jianpu", "book"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","����һ����ʫѡ��������ˮ���ݺ�һЩ���Եø�����Ŀ��

    ���������ƫ�������´�������֮��Ĥ��ͨ��ף�������͸��������֡���

\n");
		set("value", 1500);
		set("material", "paper");
		set("skill", ([
			"name":	 "tangshi-jian",      //name of the skill
			"exp_required": 1 ,	   //minimum combat experience required
			"jing_cost":    10+random(10),// jing cost every time study this
			"difficulty":	10,	   // the base int to learn this skill
			"min_skill":	0,	    // the minimum level you can learn
			"max_skill":	49	    // the maximum level you can learn
		]) );
	}
}