from fontTools.t1Lib import write
from manimlib import *


class HelloWorld(Scene):
    def construct(self):
        text = Text("hello, world")
        self.add(text)
        self.play(FadeIn(text))
        self.play(text.scale, 2, {
            'about_edge': LEFT
        })
        self.play(text.scale, 0.5)
        self.play(text.shift, LEFT * 2)
        self.play(text.move_to, TOP, {
            'aligned_edge': UP
        })
        self.play(text.shift, LEFT * 2)
        self.play(text.flip, {
            'axis': UP,
            'about_point': ORIGIN
        })
        self.play(text.flip, {
            'axis': UP,
            'about_point': ORIGIN
        })
        self.play(text.shift, RIGHT * 2)
        tex_text = TexText(r'$\int^{Life}_{Death} Roll = Life$')
        self.add(tex_text)
        self.play(ShowCreation(tex_text))
        self.play(tex_text.stretch, {
            'factor': 1.5,
            'dim': 0
        })
        self.play(tex_text.stretch, {
            'factor': 1.5,
            'dim': 1
        })
        self.play(tex_text.move_to, BOTTOM, {
            'aligned_edge': BOTTOM
        })
        self.play(text.align_to, tex_text, LEFT)

        self.play(tex_text.move_to, ORIGIN)

        self.play(text.next_to, tex_text, LEFT, {'aligned_edge': BOTTOM})

        self.play(text.set_height, {
            'height': 0.1
        })

        self.play(text.animate.set_height(height=0.2, stretch=True))
        self.play(text.animate.next_to(tex_text, LEFT))
        self.play(text.animate.move_to(ORIGIN))
        self.remove(text)
        text = Text("bye,   world")
        text.set_height(height=0.1)
        text.set_height(height=0.2, stretch=True)
        self.add(text)
        text.move_to(ORIGIN)
        self.play(text.animate.next_to(tex_text, RIGHT))

        self.wait()
