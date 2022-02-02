from __future__ import annotations

from manim import VGroup, VDict, Circle, Text, Scene, FadeIn, LEFT, RIGHT, DOWN, UP, normalize, Line, Write, Tex, UR, \
    Mobject


class BinaryTreeNode(VGroup):
    scene: Scene
    node_id: str
    label: str
    has_left: bool
    has_right: bool
    value: VDict
    font_scale: float
    radius: float
    parent: BinaryTreeNode
    left: BinaryTreeNode
    right: BinaryTreeNode
    animation_duration: float
    start_from_root: bool

    def __init__(self, scene, node_id: str, label: str, scale: float = 1, radius: float = 1,
                 animation_duration: float = 1, start_from_root=True):
        super().__init__()
        self.animation_duration = animation_duration
        self.scene = scene
        self.node_id = node_id
        self.label = label
        self.left = None
        self.right = None
        self.parent = None
        self.start_from_root = start_from_root
        self.font_scale = scale
        self.radius = radius
        self.value = self.get_node(label)
        self.add(self.value)

    def is_full(self) -> bool:
        return self.has_right() and self.has_right()

    def has_left(self) -> bool:
        return self.left is not None

    def has_right(self) -> bool:
        return self.right is not None

    def insert(self, bt_node, side_offset_multiply: float = 2.5, down_offset_multiply: float = 2.5,
               direction=LEFT, start_from_root=True) -> BinaryTreeNode:
        if self.is_full():
            raise AttributeError("This node %s is completed" % str(self.node_id))
        bt_node.parent = self
        if start_from_root:
            parents = [self]
            while parents[-1].parent is not None:
                parents.append(parents[-1].parent)
            self.scene.add(bt_node)
            bt_node.next_to(parents[-1], buff=0, direction=UP)
            parents.pop()
            self.scene.play(FadeIn(bt_node.value), run_time=bt_node.animation_duration)
            while len(parents) > 0:
                elem = parents[-1]
                self.scene.play(bt_node.value.animate.next_to(elem, buff=0), run_time=bt_node.animation_duration)
                parents.pop()
        else:
            bt_node.next_to(self.value, buff=0)
            self.scene.play(Write(bt_node.value), run_time=bt_node.animation_duration)

        if direction is LEFT and self.has_left():
            direction = RIGHT
            self.right = bt_node
        else:
            self.left = bt_node
        child_location = self.value.get_center() + \
                         side_offset_multiply * self.radius * direction + \
                         down_offset_multiply * self.radius * DOWN
        parent_child_vector = normalize(child_location - self.value.get_center())

        edge_start = (self.value.get_center() + parent_child_vector * self.radius)
        edge_end = child_location - parent_child_vector * self.radius
        edge = Line(edge_start, edge_end)

        self.scene.play(
            bt_node.value.animate.move_to(child_location),
            FadeIn(edge),
            run_time=bt_node.animation_duration)
        return bt_node

    def get_node(self, value) -> VDict:
        node = VDict({
            'node': Circle(radius=self.radius),
            'label': Text(value)
        })
        node['label'].scale(self.font_scale)
        return node

    def change_label(self, mob: Mobject) -> Mobject:
        mob.scale(self.font_scale)
        mob.move_to(self.value['label'].get_center())
        return self.value['label'].animate.become(mob)


class BinaryTreeHelper(VGroup):
    scene: Scene
    font_scale: float
    radius: float
    root: BinaryTreeNode
    nodes: dict[str, BinaryTreeNode]
    animation_duration: float
    start_from_root: bool

    def get_node(self, node_id) -> BinaryTreeNode:
        return self.nodes[node_id]

    def create_node(self, node_id: any, parent_id: any, side_offset_multiply: float = 2.5,
                    down_offset_multiply: float = 3, direction=LEFT, label: str = None) -> BinaryTreeNode:
        parent = self.nodes[parent_id]
        node = parent.insert(
            BinaryTreeNode(self.scene, str(node_id), label, self.font_scale, self.radius, self.animation_duration),
            side_offset_multiply,
            down_offset_multiply, start_from_root=self.start_from_root, direction=direction)
        self.nodes[node_id] = node
        return node

    def __init__(self, scene: Scene, font_scale: float, radius: float, root_id: str, animation_duration: float = 1,
                 root_label: str = None, start_from_root: bool = True):
        super().__init__()
        if root_label is None:
            root_label = str(root_id)
        self.scene = scene
        self.font_scale = font_scale
        self.animation_duration = animation_duration
        self.start_from_root = start_from_root
        self.radius = radius
        self.nodes = {}
        self.root = BinaryTreeNode(self.scene, root_id, root_label, self.font_scale, self.radius, animation_duration)
        self.nodes[root_id] = self.root
        self.add(self.root)


class CompletedBinaryTreeHelper(VGroup):
    scene: Scene
    font_scale: float
    radius: float
    root: BinaryTreeNode
    nodes: list[BinaryTreeNode]
    cur_idx: int
    animation_duration: float
    start_from_root: bool

    def insert(self, node_id: any, side_offset_multiply: float = 2.5,
               down_offset_multiply: float = 2.5, label: str = None) -> BinaryTreeNode:
        if label is None:
            label = str(node_id)
        elem = self.nodes[self.cur_idx]
        node = elem.insert(
            BinaryTreeNode(self.scene, str(node_id), label, self.font_scale, self.radius, self.animation_duration),
            side_offset_multiply,
            down_offset_multiply, start_from_root=self.start_from_root)
        self.nodes.append(node)
        if elem.is_full():
            self.cur_idx += 1
        return node

    def get_node(self, node_id) -> BinaryTreeNode:
        for item in self.nodes:
            if item.node_id == str(node_id):
                return item
        return None

    def __init__(self, scene: Scene, font_scale: float, radius: float, root_id: str, animation_duration: float = 1,
                 root_label: str = None, start_from_root: bool = True):
        super().__init__()
        if root_label is None:
            root_label = str(root_id)
        self.scene = scene
        self.font_scale = font_scale
        self.animation_duration = animation_duration
        self.radius = radius
        self.start_from_root = start_from_root
        self.nodes = []
        self.root = BinaryTreeNode(self.scene, root_id, root_label, self.font_scale, self.radius, animation_duration)
        self.nodes.append(self.root)
        self.cur_idx = 0
        self.scene.add(self.root)


def mark_tex_caption(node, tex) -> Write:
    nd = Tex(tex)
    nd.scale(0.45)
    nd.next_to(node, aligned_edge=UR)
    return Write(nd)
