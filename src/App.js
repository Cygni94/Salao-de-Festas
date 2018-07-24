import React from "react";
import { Component } from "react";
import { BrowserRouter as Router, Route, Switch, Link } from "react-router-dom";
import CadastroClientes from "./containers/CadastroClientes";
import CadastroFuncionario from "./containers/CadastroFuncionario";
import Home from "./containers/Home";
import ReactWidgetsForm from "./vendor/ReactWidgetsForm";

export default class App extends Component {
    render() {
        return (
            <div>
                <Router>
                    <div>
                        <nav className="navbar navbar-expand-lg navbar-light bg-light">
                            <a className="navbar-brand" href="#">
                                Salão de Festas
                            </a>
                            <button
                                className="navbar-toggler"
                                type="button"
                                data-toggle="collapse"
                                data-target="#navbarTogglerDemo02">
                                <span className="navbar-toggler-icon" />
                            </button>

                            <div
                                className="collapse navbar-collapse"
                                id="navbarTogglerDemo02">
                                <ul className="navbar-nav ml-auto mt-2 mt-lg-0">
                                    <li className="nav-item active">
                                        <Link to="/">Home</Link>
                                    </li>
                                    <li className="nav-item">
                                        <Link to="/clientes/cadastro">
                                            Cadastrar Cliente
                                        </Link>
                                    </li>
                                    <li className="nav-item">
                                        <Link to="/funcionarios/cadastro">
                                            Cadastrar Funcionário
                                        </Link>
                                    </li>
                                </ul>
                            </div>
                            <hr />
                        </nav>
                        <Switch>
                            <Route exact path="/" component={Home} />
                            <Route
                                exact
                                path="/clientes/cadastro"
                                component={CadastroClientes}
                            />
                            <Route
                                exact
                                path="/funcionarios/cadastro"
                                component={CadastroFuncionario}
                            />
                        </Switch>
                    </div>
                </Router>
            </div>
        );
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
