import React, { Component } from "react";
import CadastroClientes from "./CadastroClientes";
import ListaClientes from "./ListaClientes";

class Clientes extends Component {
    render() {
        return (
            <div>
                <CadastroClientes />
                <ListaClientes />
            </div>
        );
    }
}

export default Clientes;
