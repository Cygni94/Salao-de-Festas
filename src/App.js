import React from "react";
import { Component } from "react";
import { BrowserRouter as Router, Route, Switch, Link } from "react-router-dom";
import { Provider } from "react-redux";
import { createStore, applyMiddleware } from "redux";

import CadastroClientes from "./containers/CadastroClientes";
import CadastroFuncionario from "./containers/CadastroFuncionario";
import Home from "./containers/Home";

import reducers from "./reducers";
import promise from "redux-promise";

import "bootstrap";
import "bootstrap/dist/css/bootstrap.min.css";

const createStoreWithMiddleware = applyMiddleware(promise)(createStore);

export default class App extends Component {
    render() {
        return (
            <Provider store={createStoreWithMiddleware(reducers)}>
                <div>
                    <Router>
                        <div>
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
                                            <Link
                                                to="/clientes/cadastro"
                                                className="nav-link">
                                                Cadastrar Cliente
                                            </Link>
                                        </li>
                                        <li className="nav-item">
                                            <Link
                                                to="/funcionarios/cadastro"
                                                className="nav-link">
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
            </Provider>
        );
    }
}
