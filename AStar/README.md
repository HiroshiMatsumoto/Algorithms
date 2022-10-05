# A\*

## 考え方

> スタートノードから、あるノード n を通って、ゴールノードまでたどり着くときの最短経路を考える。

最短経路を $f^{*}$ とすると, $ f^{\*}= g^{\*}(n) + h^{\*}(n)$ と置いて考える。

$g(n)$ スタートノードから n までの最小コスト \\
$h(n)$ からゴールノードまでの最小コスト

## アルゴリズム

1. create two lists: open-list, $L_{open}$, close-list, $L_{close}$
2. create start node, $node_{S}$
3. create a set of goal nodes, $node_{G} \in G$
4. add $node_{S}$ to $L_{open}$
5. if $L_{open}$ is empty, failure search
6. pop the node with minimum $f(n)$ value in $L_{open}$, $node_{min}$
7. if $node_{min} \in G$, search ends here
8. for each neighbor node $node_{neighbor}$ of $node_{min}$:
   1. calculate $f'( node_{neighbor} ) = g( node_{min} ) + COST(node_{min}, node_{neighbor}) + h(node_{neighbor})$
   - $g(node_{min})$: cost from $node_{S}$ to $node_{min}$
   - $h(node_{neighbor})$: cost from $node_{neighbor}$ to $node_{G}$
   - $COST(node_{min}, node_{neighbor})$: cost from $node_{min}$ to $node_{neighbor}$
   2. if $node_{neighbor}$ neigher in $L_{open}$ nor $L_{close}$, store optimized cost $f'(node_{neighbor})$ as $f(node_{neighbor})$ for the route-cost of $node_{S} \rightarrow node_{min} \rightarrow node_{neighbor} \rightarrow node_{G}$ and store the $node_{neighbor}$ in $L_{open}$
   3. if $node_{neighbor}$ in $L_{open}$, and $f'(node_{neighbor}) < f(node_{neighbor})$, $f(node_{neighbor})$ from $L_{open}$, then replace the exsting $node_{neighbor}$ in $L_{open}$ with $node_{neighbor}$ with $node_{neighbor}$, whose parent node is $node_{min} and $f$ value is $f'(node_{neighbor})$
   4. if $node_{neighbor}$ in $L_{close}$, and $f'(node_{neighbor}) < f(node_{neighbor})$, $f(node_{neighbor})$ from $L_{close}$, then replace the exsting $node_{neighbor}$ in $L_{close}$ with $node_{neighbor}$ with $node_{neighbor}$, whose parent node is $node_{min} and $f$ value is $f'(node_{neighbor})$
9. repeat from step 5
10. tracing back parent nodes of the $node_{G} in G$ gives the shortest path
