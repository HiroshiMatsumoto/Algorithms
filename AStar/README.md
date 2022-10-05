# A\*

## 考え方

> スタートノードから、あるノード n を通って、ゴールノードまでたどり着くときの最短経路を考える。

最短経路を $f^{*}$ とすると, $ f^{\*}= g^{\*}(n) + h^{\*}(n)$ と置いて考える。

$g(n)$ スタートノードから n までの最小コスト \\
$h(n)$ からゴールノードまでの最小コスト

## アルゴリズム

1. create two lists: open-list, $list_{open}$, close-list, $list_{close}$
2. create start node, $node_{S}$
3. create a set of goal nodes, $node_{G} \in G$
4. add $node_{S}$ to $list_{open}$
5. if $list_{open}$ is empty, failure search
6. pop the node with minimum $f(n)$ value in $list_{open}$, $node_{min}$
7. if $node_{min} \in G$, search ends here
8. for each neighbor node $node_{neighbor}$ of $node_{min}$:
   1. calculate $f'( node_{neighbor} ) = g( node_{min} ) + COST(node_{min}, node_{neighbor}) + h(node_{neighbor})$
   - $g(node_{min})$: cost from $node_{start}$ to $node_{min}$
   - $h(node_{neighbor})$: cost from $node_{neighbor}$ to $node_{goal}$
   - $COST(node_{min}, node_{neighbor})$: cost from $node_{min}$ to $node_{neighbor}$
   2. if $node_{neighbor}$ not in neigher $list_{open}$ nor $list_{close}$, $f'(m)$
