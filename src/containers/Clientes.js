import React, { Component } from "react";
import { BrowserRouter as Router, Route, Switch, Link } from "react-router-dom";

import ListaClientes from "./ListaClientes";
import CadastroClientes from "./CadastroClientes";
import ExibirCliente from "./ExibirCliente";

class Clientes extends Component {
    render() {
        return (
            <Router>
                <div>
                    <div>
                        <Link
                            to="/clientes/cadastro"
                            className="btn btn-success">
                            Adicionar
                        </Link>
                    </div>
                    <Switch>
                        <Route
                            exact
                            path="/clientes"
                            component={ListaClientes}
                        />
                        <Route
                            exact
                            path="/clientes/cadastro"
                            component={CadastroClientes}
                        />
                        <Route
                            exact
                            path="/clientes/editar/:id"
                            component={ExibirCliente}
                        />
                    </Switch>
                </div>
            </Router>
        );
    }
}

export default Clientes;
