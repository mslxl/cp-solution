from manim import Scene, Graph, Create


class TreeGraph(Scene):
    def construct(self):
        G = Graph([], [], labels=True)
        G.scale(0.45)
        G.add_vertices(1, positions={
            1: [0, 0, 0]
        }, labels=True)
        self.play(Create(G))
        self.wait(10)
