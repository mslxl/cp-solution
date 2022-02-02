from manim import *
import networkx as nx
from binary_tree import *


class SubtitleHelper:
    scene: Scene
    mob: Mobject = None

    def __init__(self, scene) -> None:
        self.scene = scene

    def show(self, mob) -> Write:
        self.clear()
        mob.scale(0.35)
        mob.to_edge(DOWN)
        self.mob = mob
        return Write(mob)

    def get(self) -> Mobject:
        return self.mob

    def clear(self):
        if self.mob is not None:
            self.scene.remove(self.mob)


class Main(Scene):
    subtitle: SubtitleHelper

    def __init__(self, renderer=None, camera_class=Camera, always_update_mobjects=False, random_seed=None,
                 skip_animations=False):
        super().__init__(renderer, camera_class, always_update_mobjects, random_seed, skip_animations)
        self.subtitle = SubtitleHelper(self)

    def intro(self):
        text = Text("zkw 线段树")
        desc = Text("高效简单的线段树", font_size=24)
        text.move_to(ORIGIN)
        desc.next_to(text, DOWN)
        desc.align_to(text, RIGHT)
        self.play(Write(text))
        self.play(Write(desc))
        self.wait(0.5)
        self.remove(text, desc)
        self.animations.clear()

    def classicSegTree(self):
        intro = Paragraph(
            "说到线段树大家都不陌生，什么是 zkw 段树，zkw 线段树发生了什么？让小编带大家一起来看下吧（）",
            "zkw 线段树同样用于维护区间信息，在张昆玮老师的《统计的力量中》被首次提出。与经典线段树相比，它的代码更加简短，且时间常数更小。",
            "让我们先来看一下经典线段树：",
        ).scale(0.3)
        self.play(Write(intro))
        self.wait(1.5)
        title = Text("经典线段树：").scale(0.3)
        title.to_edge(UL)
        self.play(intro.animate.become(title))

        helper = BinaryTreeHelper(self, 0.4, 0.4, '1', root_label='0', animation_duration=0.4, start_from_root=False)
        helper.root.to_edge(UP)
        self.play(Write(helper.root.value), mark_tex_caption(helper.root, '$[1,10]$'),
                  self.subtitle.show(Text("我们用一棵二叉树来表示经典线段树")))
        self.wait(1)
        self.play(self.subtitle.show(Text("当我们建树时，通常从根节点开始递归建树")))
        side_offsets = [7.5, 3.8, 2.5, 1.3]
        fin_node_color = PURE_GREEN

        self.play(mark_tex_caption(helper.create_node('2', '1', side_offset_multiply=side_offsets[0], label='0').value,
                                   '$[1,5]$'))
        self.play(mark_tex_caption(
            helper.create_node('4', '2', side_offset_multiply=side_offsets[1], label='0').value,
            '$[1,3]$'))
        self.play(mark_tex_caption(
            helper.create_node('8', '4', side_offset_multiply=side_offsets[2], label='0').value,
            '$[1,2]$'))
        self.play(mark_tex_caption(
            helper.create_node('16', '8', side_offset_multiply=side_offsets[3],
                               label='1').value,
            '$[1,1]$'))
        self.play(mark_tex_caption(
            helper.create_node('17', '8', side_offset_multiply=side_offsets[3],
                               label='2').value,
            '$[2,2]$'))
        self.play(helper.get_node('8').change_label(Text('3', color=fin_node_color)))  # pull up

        self.play(mark_tex_caption(
            helper.create_node('9', '4', side_offset_multiply=side_offsets[2], label='3').value,
            '$[3,3]$'))
        self.play(helper.get_node('4').change_label(Text('6', color=fin_node_color)))  # pull up

        self.play(mark_tex_caption(
            helper.create_node('5', '2', side_offset_multiply=side_offsets[1], label='0').value,
            '$[4,5]$'))
        self.play(mark_tex_caption(
            helper.create_node('10', '5', side_offset_multiply=side_offsets[2],
                               label='4').value,
            '$[4,4]$'))
        self.play(mark_tex_caption(
            helper.create_node('11', '5', side_offset_multiply=side_offsets[2],
                               label='5').value,
            '$[5,5]$'))
        self.play(helper.get_node('5').change_label(Text('9', color=fin_node_color)))  # pull up
        self.play(helper.get_node('2').change_label(Text('15', color=fin_node_color)))  # pull up

        self.play(mark_tex_caption(
            helper.create_node('3', '1', side_offset_multiply=side_offsets[0], label='0').value,
            '$[6,10]$'))
        self.play(mark_tex_caption(
            helper.create_node('6', '3', side_offset_multiply=side_offsets[1], label='0').value,
            '$[6,8]$'))
        self.play(mark_tex_caption(
            helper.create_node('12', '6', side_offset_multiply=side_offsets[2], label='0').value,
            '$[6,7]$'))
        self.play(mark_tex_caption(
            helper.create_node('24', '12', side_offset_multiply=side_offsets[3], label='6').value,
            '$[6,6]$'))
        self.play(mark_tex_caption(
            helper.create_node('25', '12', side_offset_multiply=side_offsets[3], label='7').value,
            '$[7,7]$'))
        self.play(helper.get_node('12').change_label(Text('13', color=fin_node_color)))  # pull up

        self.play(mark_tex_caption(
            helper.create_node('13', '6', side_offset_multiply=side_offsets[2], label='8').value,
            '$[8,8]$'))
        self.play(helper.get_node('6').change_label(Text('21', color=fin_node_color)))  # pull up

        self.play(mark_tex_caption(
            helper.create_node('7', '3', side_offset_multiply=side_offsets[1], label='0').value,
            '$[9,10]$'))

        self.play(mark_tex_caption(
            helper.create_node('14', '7', side_offset_multiply=side_offsets[2], label='9').value,
            '$[9,9]$'))
        self.play(mark_tex_caption(
            helper.create_node('15', '7', side_offset_multiply=side_offsets[2], label='10').value,
            '$[10,10]$'))
        self.play(helper.get_node('7').change_label(Text('19', color=fin_node_color)))  # pull up
        self.play(helper.get_node('3').change_label(Text('40', color=fin_node_color)))  # pull up
        self.play(helper.get_node('1').change_label(Text('55', color=fin_node_color)))  # pull up
        self.wait(1)
        self.animations.clear()

    def construct(self):
        self.intro()
        self.classicSegTree()
