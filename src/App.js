import React, { Component } from "react";
import { BrowserRouter as Router, Route, Switch, Link } from "react-router-dom";

import Clientes from "./containers/Clientes";
import CadastroFuncionario from "./containers/CadastroFuncionario";
import Home from "./containers/Home";

import "./styles/css/style.css";

export default class App extends Component {
    render() {
        return (
            <Router>
                <div className="container-fluid">
                    <nav className="navbar navbar-expand-lg navbar-light bg-light">
                        <Link to="/" className="navbar-brand">
                            Salão de Festas
                        </Link>
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
                                    <Link to="/" className="nav-link">
                                        Home
                                    </Link>
                                </li>
                                <li className="nav-item">
                                    <Link to="/clientes" className="nav-link">
                                        Clientes
                                    </Link>
                                </li>
                                <li className="nav-item">
                                    <Link
                                        to="/funcionarios/cadastro"
                                        className="nav-link">
                                        Funcionários
                                    </Link>
                                </li>
                            </ul>
                        </div>
                    </nav>
                    <main className="row">
                        <div className="col-md-9">
                            <Switch>
                                <Route exact path="/" component={Home} />
                                <Route path="/clientes" component={Clientes} />
                                <Route
                                    exact
                                    path="/funcionarios/cadastro"
                                    component={CadastroFuncionario}
                                />
                            </Switch>
                        </div>
                        <aside className="col-md-3">
                            <div>
                                AQUI VIRÃO CALENDARIO, E LISTA DE TELEFONES
                            </div>
                        </aside>
                    </main>
                </div>
            </Router>
        );
    }
}
