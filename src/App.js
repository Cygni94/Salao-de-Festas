import React, { Component } from "react";
import {
    BrowserRouter as Router,
    Route,
    Switch,
    NavLink,
    Link,
} from "react-router-dom";

import Clientes from "./components/Clientes";
import Funcionarios from "./components/Funcionarios";
import Home from "./components/Home";

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
                                <li className="nav-item">
                                    <NavLink
                                        exact
                                        to="/"
                                        className="nav-link"
                                        activeClassName="active">
                                        Início
                                    </NavLink>
                                </li>
                                <li className="nav-item">
                                    <NavLink
                                        exact
                                        to="/clientes"
                                        className="nav-link"
                                        activeClassName="active">
                                        Clientes
                                    </NavLink>
                                </li>
                                <li className="nav-item">
                                    <NavLink
                                        exact
                                        to="/funcionarios"
                                        className="nav-link"
                                        activeClassName="active">
                                        Funcionários
                                    </NavLink>
                                </li>
                            </ul>
                        </div>
                    </nav>
                    <main className="row">
                        <div className="col-md-9">
                            <Switch>
                                <Route exact path="/" component={Home} />
                                <Route
                                    exact
                                    path="/clientes"
                                    component={Clientes}
                                />
                                <Route
                                    exact
                                    path="/funcionarios"
                                    component={Funcionarios}
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
