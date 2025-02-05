```mermaid
sequenceDiagram
    ViewManager<<->>LogicView: Dame X
    ViewManager-)GeneralViewRender: remderizo x
    ViewManager-)graphViewManager: Renderiza grafo
    graphViewManager<<->>layoutUtilities.cpp: obtener layout
    
    

```