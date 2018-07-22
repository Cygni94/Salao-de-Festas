import React from "react";
import { Component } from "react";

export default class App extends Component {
    render() {
        return <div>{this.props.children}</div>;
    }
}

// import React, { Component } from "react";

// import Header from "./components/header";
// import CadastroClientes from "./containers/CadastroClientes";

// class App extends Component {
//     render() {
//         return (
//             <div className="container">
//                 <Header />
//                 <CadastroClientes />
//             </div>
//         );
//     }
// }

// export default App;
